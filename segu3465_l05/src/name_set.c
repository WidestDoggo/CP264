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

    // Allocate header.
    name_set *set = (name_set*) malloc(sizeof(name_set));
    if(set == NULL) {
        return NULL;
    }

    // Initialize empty set.
    set->front = NULL;
    set->rear = NULL;
    set->count = 0;

    return set;
}

int name_set_free(name_set **source) {

    if(source == NULL || *source == NULL) {
        return 0;
    }

    int freed = 0;

    // Free all name nodes.
    name_node *node = (*source)->front;
    while(node != NULL) {
        name_node *next = node->next;
        free(node);
        node = next;
        freed += 1;
    }

    // Free header node.
    free(*source);
    *source = NULL;
    freed += 1;

    return freed;
}

bool name_set_append(name_set *source, const char *first_name, const char *last_name) {

    if(source == NULL || first_name == NULL || last_name == NULL) {
        return false;
    }

    // Only insert unique names.
    if(name_set_contains(source, first_name, last_name)) {
        return false;
    }

    // Create new node.
    name_node *node = (name_node*) malloc(sizeof(name_node));
    if(node == NULL) {
        return false;
    }

    // Copy strings safely.
    strncpy(node->first_name, first_name, NAME_LEN - 1);
    node->first_name[NAME_LEN - 1] = '\0';

    strncpy(node->last_name, last_name, NAME_LEN - 1);
    node->last_name[NAME_LEN - 1] = '\0';

    node->next = NULL;

    // Append to rear.
    if(source->rear == NULL) {
        // Empty set.
        source->front = node;
        source->rear = node;
    } else {
        source->rear->next = node;
        source->rear = node;
    }

    source->count += 1;
    return true;
}

bool name_set_contains(const name_set *source, const char *first_name, const char *last_name) {

    if(source == NULL || first_name == NULL || last_name == NULL) {
        return false;
    }

    name_node *node = source->front;

    while(node != NULL) {
        if(strcmp(node->first_name, first_name) == 0 && strcmp(node->last_name, last_name) == 0) {
            return true;
        }
        node = node->next;
    }

    return false;
}

int name_set_count(const name_set *source) {

    if(source == NULL) {
        return 0;
    }

    return source->count;
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
