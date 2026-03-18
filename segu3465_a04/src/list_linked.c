/** @file  list_linked.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "list_linked.h"

//==================================================================================
// Private Helper Functions

/**
 * Creates and returns a new list node containing a copy of item.
 */
static list_node* list_node_create(const data_type *item) {
    list_node *node = malloc(sizeof(list_node));
    if(node != NULL) {
        data_copy(&node->item, item);
        node->next = NULL;
    }
    return node;
}

//==================================================================================
// Functions

list_linked* list_initialize() {
    list_linked *source = malloc(sizeof(list_linked));
    if(source != NULL) {
        source->front = NULL;
        source->rear  = NULL;
        source->count = 0;
    }
    return source;
}

void list_destroy(list_linked **source) {
    if(source == NULL || *source == NULL) return;
    list_node *current = (*source)->front;
    while(current != NULL) {
        list_node *next = current->next;
        free(current);
        current = next;
    }
    free(*source);
    *source = NULL;
    return;
}

bool list_empty(const list_linked *source) {
    return source->count == 0;
}

int list_count(const list_linked *source) {
    return source->count;
}

bool list_append(list_linked *source, const data_type *item) {
    list_node *node = list_node_create(item);
    if(node == NULL) return false;
    if(source->rear == NULL) {
        // list is empty
        source->front = node;
        source->rear  = node;
    } else {
        source->rear->next = node;
        source->rear = node;
    }
    source->count++;
    return true;
}

bool list_prepend(list_linked *source, data_type *item) {
    list_node *node = list_node_create(item);
    if(node == NULL) return false;
    if(source->front == NULL) {
        source->front = node;
        source->rear  = node;
    } else {
        node->next = source->front;
        source->front = node;
    }
    source->count++;
    return true;
}

bool list_insert(list_linked *source, int i, data_type *item) {
    list_node *node = list_node_create(item);
    if(node == NULL) return false;

    // Clamp index
    if(i <= 0) {
        // Prepend
        node->next = source->front;
        source->front = node;
        if(source->rear == NULL) source->rear = node;
        source->count++;
        return true;
    }
    if(i >= source->count) {
        // Append
        if(source->rear == NULL) {
            source->front = node;
        } else {
            source->rear->next = node;
        }
        source->rear = node;
        source->count++;
        return true;
    }
    // Insert at position i
    list_node *current = source->front;
    for(int j = 0; j < i - 1; j++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    source->count++;
    return true;
}

bool list_peek(const list_linked *source, data_type *item) {
    if(source->front == NULL) return false;
    data_copy(item, &source->front->item);
    return true;
}

bool list_key_find(const list_linked *source, const data_type *key, data_type *item) {
    list_node *current = source->front;
    while(current != NULL) {
        if(data_compare(&current->item, key) == 0) {
            data_copy(item, &current->item);
            return true;
        }
        current = current->next;
    }
    return false;
}

bool list_key_remove(list_linked *source, const data_type *key, data_type *item) {
    list_node *prev = NULL;
    list_node *current = source->front;
    while(current != NULL) {
        if(data_compare(&current->item, key) == 0) {
            data_copy(item, &current->item);
            if(prev == NULL) {
                source->front = current->next;
            } else {
                prev->next = current->next;
            }
            if(current->next == NULL) {
                source->rear = prev;
            }
            free(current);
            source->count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool list_remove_front(list_linked *source, data_type *item) {
    if(source->front == NULL) return false;
    list_node *node = source->front;
    data_copy(item, &node->item);
    source->front = node->next;
    if(source->front == NULL) source->rear = NULL;
    free(node);
    source->count--;
    return true;
}

int list_key_index(const list_linked *source, const data_type *key) {
    list_node *current = source->front;
    int index = 0;
    while(current != NULL) {
        if(data_compare(&current->item, key) == 0) {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;
}

bool list_key_contains(const list_linked *source, const data_type *key) {
    return list_key_index(source, key) != -1;
}

int list_key_count(const list_linked *source, const data_type *key) {
    int count = 0;
    list_node *current = source->front;
    while(current != NULL) {
        if(data_compare(&current->item, key) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

bool list_index_remove(list_linked *source, int i, data_type *item) {
    if(source->front == NULL || i < 0 || i >= source->count) return false;
    list_node *prev = NULL;
    list_node *current = source->front;
    for(int j = 0; j < i; j++) {
        prev = current;
        current = current->next;
    }
    data_copy(item, &current->item);
    if(prev == NULL) {
        source->front = current->next;
    } else {
        prev->next = current->next;
    }
    if(current->next == NULL) {
        source->rear = prev;
    }
    free(current);
    source->count--;
    return true;
}

bool list_max(const list_linked *source, data_type *item) {
    if(source->front == NULL) return false;
    list_node *current = source->front;
    data_copy(item, &current->item);
    current = current->next;
    while(current != NULL) {
        if(data_compare(&current->item, item) > 0) {
            data_copy(item, &current->item);
        }
        current = current->next;
    }
    return true;
}

bool list_min(const list_linked *source, data_type *item) {
    if(source->front == NULL) return false;
    list_node *current = source->front;
    data_copy(item, &current->item);
    current = current->next;
    while(current != NULL) {
        if(data_compare(&current->item, item) < 0) {
            data_copy(item, &current->item);
        }
        current = current->next;
    }
    return true;
}

void list_clean(list_linked *source) {
    list_node *current = source->front;
    while(current != NULL) {
        // For each node, remove all subsequent duplicates
        list_node *prev = current;
        list_node *check = current->next;
        while(check != NULL) {
            if(data_compare(&check->item, &current->item) == 0) {
                list_node *dup = check;
                prev->next = check->next;
                if(check->next == NULL) source->rear = prev;
                free(dup);
                source->count--;
                check = prev->next;
            } else {
                prev = check;
                check = check->next;
            }
        }
        current = current->next;
    }
    return;
}

bool list_equal(const list_linked *target, const list_linked *source) {
    if(target->count != source->count) return false;
    list_node *t = target->front;
    list_node *s = source->front;
    while(t != NULL && s != NULL) {
        if(data_compare(&t->item, &s->item) != 0) return false;
        t = t->next;
        s = s->next;
    }
    return true;
}

void list_combine(list_linked *target, list_linked *source1, list_linked *source2) {
    // Alternate nodes from source1 and source2 into target
    while(source1->front != NULL || source2->front != NULL) {
        if(source1->front != NULL) {
            list_node *node = source1->front;
            source1->front = node->next;
            if(source1->front == NULL) source1->rear = NULL;
            source1->count--;
            node->next = NULL;
            if(target->rear == NULL) {
                target->front = node;
                target->rear  = node;
            } else {
                target->rear->next = node;
                target->rear = node;
            }
            target->count++;
        }
        if(source2->front != NULL) {
            list_node *node = source2->front;
            source2->front = node->next;
            if(source2->front == NULL) source2->rear = NULL;
            source2->count--;
            node->next = NULL;
            if(target->rear == NULL) {
                target->front = node;
                target->rear  = node;
            } else {
                target->rear->next = node;
                target->rear = node;
            }
            target->count++;
        }
    }
    return;
}

void list_split_alt(list_linked *target1, list_linked *target2, list_linked *source) {
    bool toggle = true;
    while(source->front != NULL) {
        list_node *node = source->front;
        source->front = node->next;
        if(source->front == NULL) source->rear = NULL;
        source->count--;
        node->next = NULL;

        list_linked *target = toggle ? target1 : target2;
        if(target->rear == NULL) {
            target->front = node;
            target->rear  = node;
        } else {
            target->rear->next = node;
            target->rear = node;
        }
        target->count++;
        toggle = !toggle;
    }
    return;
}

void list_split(list_linked *target1, list_linked *target2, list_linked *source) {
    // target1 gets ceiling(count/2), target2 gets the rest
    int half = (source->count + 1) / 2;  // ceiling division
    int moved = 0;
    while(source->front != NULL) {
        list_node *node = source->front;
        source->front = node->next;
        if(source->front == NULL) source->rear = NULL;
        source->count--;
        node->next = NULL;

        list_linked *target = (moved < half) ? target1 : target2;
        if(target->rear == NULL) {
            target->front = node;
            target->rear  = node;
        } else {
            target->rear->next = node;
            target->rear = node;
        }
        target->count++;
        moved++;
    }
    return;
}

void list_split_key(list_linked *target1, list_linked *target2, list_linked *source, data_type *key) {
    while(source->front != NULL) {
        list_node *node = source->front;
        source->front = node->next;
        if(source->front == NULL) source->rear = NULL;
        source->count--;
        node->next = NULL;

        list_linked *target = (data_compare(&node->item, key) < 0) ? target1 : target2;
        if(target->rear == NULL) {
            target->front = node;
            target->rear  = node;
        } else {
            target->rear->next = node;
            target->rear = node;
        }
        target->count++;
    }
    return;
}

bool list_copy(list_linked **target, const list_linked *source) {
    if(*target != NULL) {
        list_destroy(target);
    }
    *target = list_initialize();
    if(*target == NULL) return false;

    list_node *current = source->front;
    while(current != NULL) {
        if(!list_append(*target, &current->item)) return false;
        current = current->next;
    }
    return true;
}

// Prints the items in a list from front to rear.
void list_print(const list_linked *source) {
    char string[200];
    list_node *current = source->front;

    while(current != NULL) {
        data_string(string, sizeof string, &current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}