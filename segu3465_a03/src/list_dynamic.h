/** @file  list_dynamic.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef LIST_DYNAMIC_H_
#define LIST_DYNAMIC_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data.h"

// ==============================================================================================
// Definitions

/** Initial queue capacity */
#define LIST_INIT_CAPACITY 12

// ==============================================================================================
// Structures

/** list structure */
typedef struct {
/** current capacity of list */
    int capacity;
/** current count of items in list */
    int count;
/** pointer to array of data - must be initialized */
    data_type *items;
} list_dynamic;

// ==============================================================================================
// Prototypes

/**
 * Initializes an empty list.\n
 * Assigns capacity memory to items, sets count to 0.
 *
 * @param source - pointer to a list to initialize
 * @param @param capacity - the initial number of spaces for items in the queue.
 * @return - true if source initialized, false otherwise
 */
bool list_initialize(list_dynamic *source, int capacity);

/**
 * Destroys a list.\n
 * Releases all memory from items, resets capacity to 0, count to 0.
 * source must be reinitialized to be used.
 *
 * @param source - pointer to a list
 */
void list_destroy(list_dynamic *source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a list
 * @return - true if source is empty, false otherwise
 */
bool list_empty(const list_dynamic *source);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to a list
 * @return - the number of items in source
 */
int list_count(const list_dynamic *source);

/**
 * Appends a copy of item to rear of source. Increments count. If items
 * is full, provide room for more data by increasing capacity by:\n
 * 2 * capacity + 1\n
 * and resizes items to match.
 *
 * @param source - pointer to a list
 * @param item - pointer to item to append
 * @return - true if copy of item appended, false otherwise
 */
bool list_append(list_dynamic *source, const data_type *item);

/**
 * Inserts a item into source at location i. If i < 0, insert at index 0,
 * if i > source->count insert at index source->count.\n
 * Increments count.\n
 * If items
 * is full, provide room for more data by increasing capacity by:\n
 * 2 * capacity + 1\n
 * and resizes items to match.\n
 * All items to the right of items[i] must be shifted to the next index.
 *
 * @param source - pointer to a list
 * @param item - pointer to item to insert
 * @param i - the index to put the new item
 * @return - true if copy of item inserted, false otherwise
 */
bool list_insert(list_dynamic *source, const data_type *item, int i);

/**
 * Returns a copy of the item at the front of source, source is unchanged.
 *
 * @param source - pointer to a list
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (source is empty)
 */
bool list_peek(const list_dynamic *source, data_type *item);

/**
 * Removes and returns the item at index i from a list. All items to the right
 * of list[i] must be moved to the previous index.
 *
 * @param source - pointer to a list
 * @param i - index of item to remove
 * @param item - a copy of the item removed
 * @return - true if item is removed, false otherwise
 */
bool list_index_remove(list_dynamic *source, int i, data_type *item);

/**
 * Returns a copy of the item matching key in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_find(const list_dynamic *source, const data_type *key, data_type *item);

/**
 * Removes and returns the item matching key from the list. All items to the right
 * of list[i] must be moved to the previous index.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_remove(list_dynamic *source, const data_type *key, data_type *item);

/**
 * Returns the index of key in list. -1 if key not in list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - index of the location of key in list
 */
int list_key_index(const list_dynamic *source, const data_type *key);

/**
 * Determines if key is in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - true if key in list, false otherwise
 */
bool list_key_contains(const list_dynamic *source, const data_type *key);

/**
 * Determines number of times key appears in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - number of times key appears in list
 */
int list_key_count(const list_dynamic *source, const data_type *key);

/**
 * Finds the maximum item in a list.
 *
 * @param source - pointer to a list
 * @param item - pointer to the maximum item
 * @return - true if a maximum value is found, false otherwise (list is empty)
 */
bool list_max(const list_dynamic *source, data_type *item);

/**
 * Finds the minimum item in a list.
 *
 * @param source - pointer to a list
 * @param item - pointer to the minimum item
 * @return - true if a minimum value is found, false otherwise (list is empty)
 */
bool list_min(const list_dynamic *source, data_type *item);

/**
 * Compares two lists for equality. Lists are equal if they contain equivalent items
 * in the same order and the same count.
 *
 * @param source - the first list to compare
 * @param target - the second list to compare
 * @return - true if lists are identical, false otherwise
 */
bool list_equal(const list_dynamic *source, const list_dynamic *target);

/**
 * Copies contents of source to target. target is destroyed and reinitialized
 * if necessary.
 *
 * @param target - the list to copy to
 * @param source - the list to copy from
 * @return - true if source is copied to target, false otherwise
 */
bool list_copy(list_dynamic *target, const list_dynamic *source);

/**
 * Prints the items in a list from front to rear.
 *
 * @param source - pointer to a list.
 */
void list_print(const list_dynamic *source);

#endif /* LIST_DYNAMIC_H_ */
