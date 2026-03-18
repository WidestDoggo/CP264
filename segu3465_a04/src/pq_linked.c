/** @file  pq_linked.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
//==================================================================================
// Includes
#include "pq_linked.h"

//==================================================================================
// Private Helper Functions

/**
 * Creates and returns a new pq node containing a copy of item.
 */
static pq_node* pq_node_create(const data_type *item) {
    pq_node *node = malloc(sizeof(pq_node));
    if(node != NULL) {
        data_copy(&node->item, item);
        node->next = NULL;
    }
    return node;
}

//==================================================================================
// Functions

pq_linked* pq_initialize() {
    pq_linked *source = malloc(sizeof(pq_linked));
    if(source != NULL) {
        source->front = NULL;
        source->rear  = NULL;
        source->count = 0;
    }
    return source;
}

void pq_destroy(pq_linked **source) {
    if(source == NULL || *source == NULL) return;
    pq_node *current = (*source)->front;
    while(current != NULL) {
        pq_node *next = current->next;
        free(current);
        current = next;
    }
    free(*source);
    *source = NULL;
    return;
}

bool pq_empty(const pq_linked *source) {
    return source->count == 0;
}

int pq_count(const pq_linked *source) {
    return source->count;
}

bool pq_insert(pq_linked *source, const data_type *item) {
    pq_node *node = pq_node_create(item);
    if(node == NULL) return false;

    // Insert in descending priority order (highest first)
    if(source->front == NULL || data_compare(item, &source->front->item) > 0) {
        // New node goes to the front
        node->next = source->front;
        source->front = node;
        if(source->rear == NULL) source->rear = node;
    } else {
        // Find insertion position
        pq_node *current = source->front;
        while(current->next != NULL && data_compare(item, &current->next->item) <= 0) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        if(node->next == NULL) source->rear = node;
    }
    source->count++;
    return true;
}

bool pq_peek(const pq_linked *source, data_type *item) {
    if(source->front == NULL) return false;
    data_copy(item, &source->front->item);
    return true;
}

bool pq_remove(pq_linked *source, data_type *item) {
    if(source->front == NULL) return false;
    pq_node *node = source->front;
    data_copy(item, &node->item);
    source->front = node->next;
    if(source->front == NULL) source->rear = NULL;
    free(node);
    source->count--;
    return true;
}

bool pq_equal(const pq_linked *source, const pq_linked *target) {
    if(source->count != target->count) return false;
    pq_node *s = source->front;
    pq_node *t = target->front;
    while(s != NULL && t != NULL) {
        if(data_compare(&s->item, &t->item) != 0) return false;
        s = s->next;
        t = t->next;
    }
    return true;
}

bool pq_copy(pq_linked **target, const pq_linked *source) {
    if(*target != NULL) {
        pq_destroy(target);
    }
    *target = pq_initialize();
    if(*target == NULL) return false;

    pq_node *current = source->front;
    while(current != NULL) {
        pq_node *node = pq_node_create(&current->item);
        if(node == NULL) return false;
        if((*target)->rear == NULL) {
            (*target)->front = node;
            (*target)->rear  = node;
        } else {
            (*target)->rear->next = node;
            (*target)->rear = node;
        }
        (*target)->count++;
        current = current->next;
    }
    return true;
}

void pq_print(const pq_linked *source) {
    char string[200];
    pq_node *curr = source->front;

    while(curr != NULL) {
        data_string(string, sizeof string, &curr->item);
        printf("%s\n", string);
        curr = curr->next;
    }
    return;
}