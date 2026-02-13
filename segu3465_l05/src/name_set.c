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

    // your code here

    return NULL;
}

int name_set_free(name_set **source) {

    // your code here

    return 0;
}

bool name_set_append(name_set *source, const char *first_name, const char *last_name) {

    // your code here

    return false;
}

bool name_set_contains(const name_set *source, const char *first_name, const char *last_name) {

    // your code here

    return false;
}

int name_set_count(const name_set *source) {

    // your code here

    return 0;
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
