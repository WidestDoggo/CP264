/** @file  bst_linked.c
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "bst_linked.h"

// Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

//==================================================================================
// Private Helper Functions

/**
 * Private helper function to print contents of BST in preorder.
 *
 * @param node - pointer to bst_node
 */
static void bst_print_aux(bst_node *node) {
    char string[200];

    if(node != NULL) {
        data_string(string, sizeof string, &node->item);
        printf("%s, ", string);
        bst_print_aux(node->left);
        bst_print_aux(node->right);
    }
    return;
}

/**
 * Initializes a new BST node with a copy of item.
 *
 * @param item - pointer to the value to copy to the node
 * @return - a pointer to a new BST node, NULL if memory not allocated
 */
static bst_node* bst_node_initialize(const data_type *item) {
    bst_node *node = malloc(sizeof *node);

    if(node != NULL) {
        data_copy(&node->item, item);
        node->height = 1;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

/**
 * Determines the height of node - empty nodes have a height of 0.
 *
 * @param node - pointer to a BST node
 * @return - the height of the current node
 */
static int bst_node_height(const bst_node *node) {
    int height = 0;

    if(node != NULL) {
        height = node->height;
    }
    return height;
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 *
 * @param node - pointer to a BST node
 */
static void bst_update_height(bst_node *node) {
    int left_height = bst_node_height(node->left);
    int right_height = bst_node_height(node->right);

    node->height = MAX_HEIGHT(left_height, right_height) + 1;
    return;
}

/**
 * Inserts a copy of item into source. Insertion must preserve the BST definition.
 * item may appear only once in source.
 *
 * @param source - pointer to a BST
 * @param node - pointer to a BST node
 * @param item - the item to insert
 * @return - true if item inserted, false otherwise
 */
static bool bst_insert_aux(bst_linked *source, bst_node **node, const data_type *item) {
    bool inserted = false;

    if(*node == NULL) {
        // Base case: add a new node containing the item.
        *node = bst_node_initialize(item);
        source->count += 1;
        inserted = true;
    } else {
        // Compare the node data_type against the new item.
        int comp = data_compare(item, &(*node)->item);

        if(comp < 0) {
            // General case: check the left subsource.
            inserted = bst_insert_aux(source, &(*node)->left, item);
        } else if(comp > 0) {
            // General case: check the right subsource.
            inserted = bst_insert_aux(source, &(*node)->right, item);
        }
    }
    if(inserted) {
        // Update the node height if any of its children have been changed.
        bst_update_height(*node);
    }
    return inserted;
}

/**
 * Private helper: recursively destroys all nodes in the BST.
 *
 * @param node - pointer to a BST node
 */
static void bst_destroy_aux(bst_node **node) {
    if(*node != NULL) {
        bst_destroy_aux(&(*node)->left);
        bst_destroy_aux(&(*node)->right);
        free(*node);
        *node = NULL;
    }
}

/**
 * Private helper: inorder traversal, filling items array.
 *
 * @param node  - pointer to a BST node
 * @param items - array to fill
 * @param index - pointer to current index in items array
 */
static void bst_inorder_aux(const bst_node *node, data_type *items, int *index) {
    if(node != NULL) {
        bst_inorder_aux(node->left, items, index);
        data_copy(&items[*index], &node->item);
        (*index)++;
        bst_inorder_aux(node->right, items, index);
    }
}

/**
 * Private helper: preorder traversal, filling items array.
 *
 * @param node  - pointer to a BST node
 * @param items - array to fill
 * @param index - pointer to current index in items array
 */
static void bst_preorder_aux(const bst_node *node, data_type *items, int *index) {
    if(node != NULL) {
        data_copy(&items[*index], &node->item);
        (*index)++;
        bst_preorder_aux(node->left, items, index);
        bst_preorder_aux(node->right, items, index);
    }
}

/**
 * Private helper: postorder traversal, filling items array.
 *
 * @param node  - pointer to a BST node
 * @param items - array to fill
 * @param index - pointer to current index in items array
 */
static void bst_postorder_aux(const bst_node *node, data_type *items, int *index) {
    if(node != NULL) {
        bst_postorder_aux(node->left, items, index);
        bst_postorder_aux(node->right, items, index);
        data_copy(&items[*index], &node->item);
        (*index)++;
    }
}

/**
 * Private helper: recursively copies a subtree.
 *
 * @param node - pointer to a BST node in the source tree
 * @return - pointer to a new copy of the subtree, NULL on failure
 */
static bst_node* bst_copy_aux(const bst_node *node) {
    if(node == NULL) {
        return NULL;
    }
    bst_node *new_node = bst_node_initialize(&node->item);
    if(new_node != NULL) {
        new_node->height = node->height;
        new_node->left  = bst_copy_aux(node->left);
        new_node->right = bst_copy_aux(node->right);
    }
    return new_node;
}

/**
 * Private helper: counts leaf nodes (nodes with no children).
 *
 * @param node - pointer to a BST node
 * @return - count of leaf nodes
 */
static int bst_leaf_count_aux(const bst_node *node) {
    if(node == NULL) {
        return 0;
    }
    if(node->left == NULL && node->right == NULL) {
        return 1;
    }
    return bst_leaf_count_aux(node->left) + bst_leaf_count_aux(node->right);
}

/**
 * Private helper: counts nodes with exactly one child.
 *
 * @param node - pointer to a BST node
 * @return - count of one-child nodes
 */
static int bst_one_child_count_aux(const bst_node *node) {
    if(node == NULL) {
        return 0;
    }
    int count = 0;
    if((node->left == NULL) != (node->right == NULL)) {
        count = 1;
    }
    return count
        + bst_one_child_count_aux(node->left)
        + bst_one_child_count_aux(node->right);
}

/**
 * Private helper: counts nodes with two children.
 *
 * @param node - pointer to a BST node
 * @return - count of two-child nodes
 */
static int bst_two_child_count_aux(const bst_node *node) {
    if(node == NULL) {
        return 0;
    }
    int count = (node->left != NULL && node->right != NULL) ? 1 : 0;
    return count
        + bst_two_child_count_aux(node->left)
        + bst_two_child_count_aux(node->right);
}

/**
 * Private helper: accumulates zero/one/two child node counts.
 *
 * @param node - pointer to a BST node
 * @param zero - pointer to leaf count
 * @param one  - pointer to one-child count
 * @param two  - pointer to two-child count
 */
static void bst_node_counts_aux(const bst_node *node, int *zero, int *one, int *two) {
    if(node == NULL) {
        return;
    }
    bool has_left  = node->left  != NULL;
    bool has_right = node->right != NULL;

    if(!has_left && !has_right) {
        (*zero)++;
    } else if(has_left && has_right) {
        (*two)++;
    } else {
        (*one)++;
    }
    bst_node_counts_aux(node->left,  zero, one, two);
    bst_node_counts_aux(node->right, zero, one, two);
}

/**
 * Private helper: checks whether a subtree is balanced.
 * Returns -1 if unbalanced, otherwise returns the subtree height.
 *
 * @param node - pointer to a BST node
 * @return - height if balanced, -1 if not balanced
 */
static int bst_balanced_aux(const bst_node *node) {
    if(node == NULL) {
        return 0;
    }
    int left_h  = bst_balanced_aux(node->left);
    if(left_h == -1) return -1;

    int right_h = bst_balanced_aux(node->right);
    if(right_h == -1) return -1;

    int diff = left_h - right_h;
    if(diff > 1 || diff < -1) {
        return -1;
    }
    return MAX_HEIGHT(left_h, right_h) + 1;
}

/**
 * Private helper: validates BST ordering property.
 * Every value in left subtree must be < node, every value in right must be > node.
 *
 * @param node - pointer to a BST node
 * @param min  - pointer to minimum allowed value (NULL = no lower bound)
 * @param max  - pointer to maximum allowed value (NULL = no upper bound)
 * @return - true if valid BST, false otherwise
 */
static bool bst_valid_aux(const bst_node *node, const data_type *min, const data_type *max) {
    if(node == NULL) {
        return true;
    }
    // Check BST ordering
    if(min != NULL && data_compare(&node->item, min) <= 0) {
        return false;
    }
    if(max != NULL && data_compare(&node->item, max) >= 0) {
        return false;
    }
    // Check stored height matches actual computed height
    int left_h  = bst_node_height(node->left);
    int right_h = bst_node_height(node->right);
    int expected_height = MAX_HEIGHT(left_h, right_h) + 1;
    if(node->height != expected_height) {
        return false;
    }
    return bst_valid_aux(node->left,  min, &node->item)
        && bst_valid_aux(node->right, &node->item, max);
}

/**
 * Private helper: checks structural equality of two subtrees.
 *
 * @param t1 - pointer to a BST node in tree 1
 * @param t2 - pointer to a BST node in tree 2
 * @return - true if subtrees are identical, false otherwise
 */
static bool bst_equal_aux(const bst_node *t1, const bst_node *t2) {
    if(t1 == NULL && t2 == NULL) {
        return true;
    }
    if(t1 == NULL || t2 == NULL) {
        return false;
    }
    return data_compare(&t1->item, &t2->item) == 0
        && bst_equal_aux(t1->left,  t2->left)
        && bst_equal_aux(t1->right, t2->right);
}

/**
 * Private helper: removes and returns the node with the maximum value
 * in a subtree (rightmost node), used during bst_remove.
 *
 * @param node - pointer to pointer to a BST node
 * @return - pointer to the removed max node (caller must free)
 */
static bst_node* bst_remove_max_node(bst_node **node) {
    if((*node)->right == NULL) {
        // This is the rightmost (max) node
        bst_node *max_node = *node;
        *node = (*node)->left;   // promote left child (may be NULL)
        return max_node;
    }
    bst_node *max_node = bst_remove_max_node(&(*node)->right);
    bst_update_height(*node);
    return max_node;
}

/**
 * Private helper: recursively removes the node matching key.
 *
 * @param source - pointer to the BST header
 * @param node   - pointer to pointer to current node
 * @param key    - value to remove
 * @param item   - pointer to store the removed value
 * @return - true if removed, false otherwise
 */
static bool bst_remove_aux(bst_linked *source, bst_node **node,
                            const data_type *key, data_type *item) {
    if(*node == NULL) {
        return false;   // key not found
    }
    bool removed = false;
    int comp = data_compare(key, &(*node)->item);

    if(comp < 0) {
        removed = bst_remove_aux(source, &(*node)->left, key, item);
    } else if(comp > 0) {
        removed = bst_remove_aux(source, &(*node)->right, key, item);
    } else {
        // Found the node to remove
        data_copy(item, &(*node)->item);
        bst_node *to_free = *node;

        if((*node)->left == NULL) {
            *node = (*node)->right;
        } else if((*node)->right == NULL) {
            *node = (*node)->left;
        } else {
            // Two children: replace with inorder predecessor (max of left subtree)
            bst_node *pred = bst_remove_max_node(&(*node)->left);
            pred->left  = (*node)->left;
            pred->right = (*node)->right;
            *node = pred;
            bst_update_height(*node);
        }
        free(to_free);
        source->count--;
        removed = true;
    }
    if(removed && *node != NULL) {
        bst_update_height(*node);
    }
    return removed;
}

//==================================================================================
// Functions

bst_linked* bst_initialize() {
    // Allocate memory to the list header
    bst_linked *source = malloc(sizeof *source);

    if(source) {
        // Initialize the list structure
        source->root = NULL;
        source->count = 0;
    }
    // returns NULL if malloc fails
    return source;
}

void bst_destroy(bst_linked **source) {
    if(source != NULL && *source != NULL) {
        bst_destroy_aux(&(*source)->root);
        free(*source);
        *source = NULL;
    }
    return;
}

bool bst_empty(const bst_linked *source) {
    return source->root == NULL;
}

int bst_count(const bst_linked *source) {
    return source->count;
}

void bst_inorder(const bst_linked *source, data_type *items) {
    int index = 0;
    bst_inorder_aux(source->root, items, &index);
    return;
}

void bst_preorder(const bst_linked *source, data_type *items) {
    int index = 0;
    bst_preorder_aux(source->root, items, &index);
    return;
}

void bst_postorder(const bst_linked *source, data_type *items) {
    int index = 0;
    bst_postorder_aux(source->root, items, &index);
    return;
}

bool bst_insert(bst_linked *source, const data_type *item) {
    return bst_insert_aux(source, &(source->root), item);
}

bool bst_retrieve(const bst_linked *source, const data_type *key, data_type *item) {
    const bst_node *current = source->root;

    while(current != NULL) {
        int comp = data_compare(key, &current->item);
        if(comp < 0) {
            current = current->left;
        } else if(comp > 0) {
            current = current->right;
        } else {
            data_copy(item, &current->item);
            return true;
        }
    }
    return false;
}

bool bst_remove(bst_linked *source, const data_type *key, data_type *item) {
    return bst_remove_aux(source, &source->root, key, item);
}

bool bst_copy(bst_linked **target, const bst_linked *source) {
    *target = bst_initialize();
    if(*target == NULL) {
        return false;
    }
    (*target)->root  = bst_copy_aux(source->root);
    (*target)->count = source->count;
    return true;
}

bool bst_max(const bst_linked *source, data_type *item) {
    if(source->root == NULL) {
        return false;
    }
    const bst_node *current = source->root;
    while(current->right != NULL) {
        current = current->right;
    }
    data_copy(item, &current->item);
    return true;
}

bool bst_min(const bst_linked *source, data_type *item) {
    if(source->root == NULL) {
        return false;
    }
    const bst_node *current = source->root;
    while(current->left != NULL) {
        current = current->left;
    }
    data_copy(item, &current->item);
    return true;
}

int bst_leaf_count(const bst_linked *source) {
    return bst_leaf_count_aux(source->root);
}

int bst_one_child_count(const bst_linked *source) {
    return bst_one_child_count_aux(source->root);
}

int bst_two_child_count(const bst_linked *source) {
    return bst_two_child_count_aux(source->root);
}

void bst_node_counts(const bst_linked *source, int *zero, int *one, int *two) {
    *zero = 0;
    *one  = 0;
    *two  = 0;
    bst_node_counts_aux(source->root, zero, one, two);
    return;
}

bool bst_balanced(const bst_linked *source) {
    return bst_balanced_aux(source->root) != -1;
}

bool bst_valid(const bst_linked *source) {
    return bst_valid_aux(source->root, NULL, NULL);
}

bool bst_equal(const bst_linked *target, const bst_linked *source) {
    return bst_equal_aux(target->root, source->root);
}

void bst_print(const bst_linked *source) {
    // can print root height only if root is not NULL
    printf("  count: %d, height: %d, items:\n{", source->count, source->root ? source->root->height : 0);
    bst_print_aux(source->root);
    printf("}\n");
    return;
}