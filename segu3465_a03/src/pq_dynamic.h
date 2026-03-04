/** @file  pq_dynamic.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef PQ_DYNAMIC_H_
#define PQ_DYNAMIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"

// ==============================================================================================
// Definitions

/** Initial priority queue capacity */
#define PQ_INIT_CAPACITY 12

// ==============================================================================================
// Structures

/** priority queue structure */
typedef struct {
/** current capacity of queue */
    int capacity;
/** current count of items in queue */
    int count;
/** index of highest priority item in queue */
    int first;
/** pointer to array of data - must be initialized */
    data_type *items;
} pq_dynamic;

// ==============================================================================================
// Prototypes

/**
 * Initializes an empty priority queue.\n
 * Assigns capacity memory to items and sets first to -1.
 *
 * @param source - pointer to a priority queue to initialize.
 * @param capacity - the initial number of spaces for items in the priority queue.
 * @return - true if source initialized, false otherwise
 */
bool pq_initialize(pq_dynamic *source, int capacity);

/**
 * Destroys a priority queue.\n
 * Releases all memory from items, resets capacity to 0, first to -1, count to 0.
 * source must be reinitialized to be used.
 *
 * @param source - pointer to a priority queue
 */
void pq_destroy(pq_dynamic *source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a priority queue
 * @return - true if source is empty, false otherwise
 */
bool pq_empty(const pq_dynamic *source);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to a priority queue
 * @return - the number of items in source
 */
int pq_count(const pq_dynamic *source);

/**
 * Adds a copy of item to the rear of source. Increments count. Updates
 * first as appropriate. If items is full, provide room for more data by
 * increasing capacity by:\n
 * 2 * capacity + 1\n
 * and resizes items to match.
 *
 * @param source - pointer to a priority queue
 * @param item - pointer to item to insert
 * @return - true if copy of item inserted, false otherwise
 */
bool pq_insert(pq_dynamic *source, const data_type *item);

/**
 * Returns a copy of highest priority item in source, source is unchanged.
 *
 * @param source - pointer to a priority queue
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (source is empty)
 */
bool pq_peek(const pq_dynamic *source, data_type *item);

/**
 * Removes and returns the highest priority item of source. Value at
 * end of items takes place of value removed from first. Updates first
 * to highest priority item in remaining values, decrements count.
 * If the last item is removed, first is set to -1.
 *
 * @param source - pointer to a priority queue
 * @param item - pointer to item to removed item
 * @return - true if first item removed, false otherwise (source is empty)
 */
bool pq_remove(pq_dynamic *source, data_type *item);

/**
 * Compares two priority queues for equality. Priority queues are equal if they contain
 * equivalent items in the same order and the same count.
 *
 * @param source - the first priority queue to compare
 * @param target - the second priority queue to compare
 * @return - true if priority queues are identical, false otherwise
 */
bool pq_equal(const pq_dynamic *source, const pq_dynamic *target);

/**
 * Copies contents of source to target. target is destroyed and reinitialized
 * if necessary.
 *
 * @param target - the priority queue to copy to
 * @param source - the priority queue to copy from
 * @return - true if source is copied to target, false otherwise
 */
bool pq_copy(pq_dynamic *target, const pq_dynamic *source);

/**
 * Prints the items in a priority queue from front to rear of items.
 * (For testing only).
 *
 * @param source - pointer to a priority queue
 */
void pq_print(const pq_dynamic *source);

#endif /* PQ_DYNAMIC_H_ */
