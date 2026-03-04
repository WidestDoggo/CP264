/** @file  stack_dynamic.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef STACK_DYNAMIC_H_
#define STACK_DYNAMIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"

// ==============================================================================================
// Definitions

/** Initial stack capacity */
#define STACK_INIT_CAPACITY 12

// ==============================================================================================
// Structures

/** stack structure */
typedef struct {
/** current capacity of the stack */
    int capacity;
/** index of top item of the stack */
    int top;
/** pointer to array of data - must be initialized */
    data_type *items;
} stack_dynamic;

// ==============================================================================================
// Prototypes

/**
 * Initializes an empty stack.\n
 * Assigns capacity memory to items and sets top to -1.
 *
 * @param source - pointer to a stack
 * @param capacity - the initial number of spaces for items in the stack
 * @return - true if source initialized, false otherwise
 */
bool stack_initialize(stack_dynamic *source, int capacity);

/**
 * Destroys a stack.\n
 * Releases all memory from items, resets capacity to 0 and top to -1.
 * source must be reinitialized to be used.
 *
 * @param source - pointer to a stack
 */
void stack_destroy(stack_dynamic *source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a stack.
 * @return - true if source is empty, false otherwise.
 */
bool stack_empty(const stack_dynamic *source);

/**
 * Pushes a copy of item onto the top of source. Increments top. If items
 * is full, provide room for more data by increasing capacity by:\n
 * 2 * capacity + 1\n
 * and resizes items to match.
 *
 * @param source - pointer to a stack
 * @param item - pointer to item to push
 * @return - true if copy of item pushed, false otherwise
 */
bool stack_push(stack_dynamic *source, const data_type *item);

/**
 * Returns a copy of the item on the top of source, source is unchanged.
 *
 * @param source - pointer to a stack
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (source is empty)
 */
bool stack_peek(const stack_dynamic *source, data_type *item);

/**
 * Removes and returns the item at the top of source. Decrements top.
 * If the last item is popped, top is set to -1.
 *
 * @param source - pointer to a stack
 * @param item - pointer to item to popped item
 * @return - true if top item popped, false otherwise (source is empty)
 */
bool stack_pop(stack_dynamic *source, data_type *item);

/**
 * Compares two stacks for equality. Stacks are equal if they contain equivalent items
 * in the same order and the same count.
 *
 * @param source - the first stack to compare
 * @param target - the second stack to compare
 * @return - true if stacks are identical, false otherwise
 */
bool stack_equal(const stack_dynamic *source, const stack_dynamic *target);

/**
 * Copies contents of source to target. target is destroyed and reinitialized
 * if necessary.
 *
 * @param target - the stack to copy to
 * @param source - the stack to copy from
 * @return - true if source is copied to target, false otherwise
 */
bool stack_copy(stack_dynamic *target, const stack_dynamic *source);

/**
 * Prints the items in source from top to bottom of stack.
 * (For testing only).
 *
 * @param source - pointer to a stack
 */
void stack_print(const stack_dynamic *source);

#endif /* STACK_DYNAMIC_H_ */
