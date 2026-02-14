/** @file  name_set.c
 * -------------------------------------
 * @author your name, your ID, your email
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "name_set.h"

// ==============================================================================================
// Functions

name_set* name_set_initialize() {

    name_set *set = malloc(sizeof(name_set));
    if (set != NULL) {
        set->front = NULL;
    }

    return set;
}

int name_set_free(name_set **source) {

    int count = 0;

    if (source != NULL && *source != NULL) {

        name_node *current = (*source)->front;

        while (current != NULL) {
            name_node *temp = current;
            current = current->next;

            free(temp->first_name);
            free(temp->last_name);
            free(temp);
            count++;
        }

        free(*source);
        *source = NULL;
    }

    return count;
}

bool name_set_append(name_set *source, const char *first_name, const char *last_name) {

    if (source == NULL || first_name == NULL || last_name == NULL) {
        return false;
    }

    if (name_set_contains(source, first_name, last_name)) {
        return false;
    }

    name_node *node = malloc(sizeof(name_node));
    if (node == NULL) {
        return false;
    }

    node->first_name = strdup(first_name);
    node->last_name = strdup(last_name);
    node->next = source->front;

    source->front = node;

    return true;
}

bool name_set_contains(const name_set *source, const char *first_name, const char *last_name) {

    if (source == NULL) {
        return false;
    }

    name_node *current = source->front;

    while (current != NULL) {
        if (strcmp(current->first_name, first_name) == 0 &&
            strcmp(current->last_name, last_name) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

int name_set_count(const name_set *source) {

    if (source == NULL) {
        return 0;
    }

    int count = 0;
    name_node *current = source->front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void name_set_print(const name_set *source) {
    // Set node to point to the first node in the set.
    name_node *node = source->front;

    // Traverse the set.
    while(node != NULL) {
        printf("%s, %s\n", node->last_name, node->first_name);
        // Update the pointer to the next node.
        node = node->next;
    }
    return;
}
