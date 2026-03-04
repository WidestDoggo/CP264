/** @file  queue_dynamic.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef QUEUE_DYNAMIC_H_
#define QUEUE_DYNAMIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"

// ==============================================================================================
// Definitions

/** Initial queue capacity */
#define QUEUE_INIT_CAPACITY 12

// ==============================================================================================
// Structures

/** queue structure */
typedef struct {
/** current capacity of queue */
    int capacity;
/** current count of items in queue */
    int count;
/** index of front of queue */
    int front;
/** index of next empty array element in queue */
    int rear;
/** pointer to array of data - must be initialized */
    data_type *items;
} queue_dynamic;

// ==============================================================================================
// Prototypes

/**
 * Initializes an empty queue.\n
 * Assigns capacity memory to items, sets front to -1, rear to 0, and count to 0.
 *
 * @param source - pointer to a queue to initialize
 * @param @param capacity - the initial number of spaces for items in the queue
 * @return - true if source initialized, false otherwise
 */
bool queue_initialize(queue_dynamic *source, int capacity);

/**
 * Destroys a queue.\n
 * Releases all memory from items, resets capacity to 0, front to -1,
 * rear to 0, count to 0. source must be reinitialized to be used.
 *
 * @param source - pointer to a queue
 */
void queue_destroy(queue_dynamic *source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a queue
 * @return - true if source is empty, false otherwise
 */
bool queue_empty(const queue_dynamic *source);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to a queue
 * @return - the number of items in source
 */
int queue_count(const queue_dynamic *source);

/**
 * Adds a copy of item to the rear of source. Increments rear and count.
 * If items is full, provide room for more data by increasing capacity by:\n
 * 2 * capacity + 1\n
 * and resizes items to match.
 *
 * @param source - pointer to a queue
 * @param item - pointer to item to insert
 * @return - true if copy of item inserted, false otherwise
 */
bool queue_insert(queue_dynamic *source, const data_type *item);

/**
 * Returns a copy of the item at the front of source, source is unchanged.
 *
 * @param source - pointer to a queue
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (source is empty)
 */
bool queue_peek(const queue_dynamic *source, data_type *item);

/**
 * Removes and returns the item at the front of source. Increments front,
 * decrements count. If the last item is removed, front is set to -1.
 *
 * @param source - pointer to a queue
 * @param item - pointer to item to removed item
 * @return - true if front item removed, false otherwise (source is empty)
 */
bool queue_remove(queue_dynamic *source, data_type *item);

/**
 * Compares two queues for equality. Queues are equal if they contain equivalent items
 * in the same order and the same count. front and rear indexes need not be identical
 * between source and target.
 *
 * @param source - the first queue to compare
 * @param target - the second queue to compare
 * @return - true if queues are identical, false otherwise
 */
bool queue_equal(const queue_dynamic *target, const queue_dynamic *source);

/**
 * Copies contents of source to target. target is destroyed and reinitialized
 * if necessary.
 *
 * @param target - the queue to copy to
 * @param source - the queue to copy from
 * @return - true if source is copied to target, false otherwise
 */
bool queue_copy(queue_dynamic *target, const queue_dynamic *source);

/**
 * Prints the items in a queue from front to rear of queue.
 * (For testing only).
 *
 * @param source - pointer to a queue
 */
void queue_print(const queue_dynamic *source);

#endif /* QUEUE_DYNAMIC_H_ */
