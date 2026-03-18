/** @file  pq_linked.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef PQ_LINKED_H_
#define PQ_LINKED_H_

// ==============================================================================================
// Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data.h"

// ==============================================================================================
// Structures

/**
 * Priority Queue node.
 */
typedef struct PQ_NODE {
/** Node data */
    data_type item;
/** Pointer to the next priority queue node */
    struct PQ_NODE *next;
} pq_node;

/**
 * Priority Queue header.
 */
typedef struct {
/** Pointer to the front node of the priority queue */
    pq_node *front;
/** Pointer to the rear node of the priority queue */
    pq_node *rear;
/** Number of items in queue. */
    int count;
} pq_linked;

// ==============================================================================================
// Prototypes

/**
 * Initializes an empty priority queue.\n
 * front and rear are initialized to NULL, count to 0.
 *
 * @return - pointer to a priority queue, NULL if memory cannot be allocated
 */
pq_linked* pq_initialize();

/**
 * Destroys a priority queue.\n
 * Releases all memory from all nodes including header node.
 * source must be reinitialized to be used.
 *
 * @param source - pointer to a priority queue
 */
void pq_destroy(pq_linked **source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a priority queue
 * @return - true if source is empty, false otherwise
 */
bool pq_empty(const pq_linked *source);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to a priority queue
 * @return - the number of items in source
 */
int pq_count(const pq_linked *source);

/**
 * Inserts a copy of item into source. Items are stored in order
 * from highest priority to lowest priority.
 *
 * @param source - pointer to a priority queue
 * @param item - the item to insert
 * @return - true if copy of item inserted, false otherwise
 */
bool pq_insert(pq_linked *source, const data_type *item);

/**
 * Returns a copy of the highest priority item in source.
 * Such item should be at the front of source.
 *
 * @param source - pointer to a priority queue
 * @param item - the item to peek
 * @return - true if item peeked, false otherwise (source is empty)
 */
bool pq_peek(const pq_linked *source, data_type *item);

/**
 * Returns and removes the item at the front of source. This is
 * the item with the highest priority in source.
 *
 * @param source - pointer to a priority queue
 * @param item - the item to peek
 * @return - true if item removed, false otherwise (source is empty)
 */
bool pq_remove(pq_linked *source, data_type *item);

/**
 * Compares two queues for equality. queues are equal if they contain equivalent items
 * in the same order.
 *
 * @param source - the first queue to compare
 * @param target - the second queue to compare
 * @return - true if queues are identical, false otherwise
 */
bool pq_equal(const pq_linked *source, const pq_linked *target);

/**
 * Copies contents of source to target. target is destroyed and reinitialized
 * if necessary.
 *
 * @param target - the priority queue to copy to
 * @param source - the priority queue to copy from
 * @return - true if source is copied to target, false otherwise
 */
bool pq_copy(pq_linked **target, const pq_linked *source);

/**
 * Prints the items in a priority queue from front to rear.
 * (For testing only).
 *
 * @param source - pointer to a priority queue
 */
void pq_print(const pq_linked *source);

#endif /* PQ_LINKED_H_ */
