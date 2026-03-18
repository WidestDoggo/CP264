/** @file  list_linked.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef LIST_linked_H_
#define LIST_linked_H_

// ==============================================================================================
// Includes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"

// ==============================================================================================
// Structures

/**
 * List node.
 */
typedef struct LIST_NODE {
/** Node data */
    data_type item;
/** Pointer to the next list node */
    struct LIST_NODE *next;
} list_node;

/**
 * List header.
 */
typedef struct {
/** Pointer to the front node of the list */
    list_node *front;
/** Pointer to the rear node of the list */
    list_node *rear;
/** Number of items in list */
    int count;
} list_linked;

//==================================================================================
// Prototypes

/**
 * Initializes a list.
 *
 * @return - pointer to a new list
 */
list_linked* list_initialize();

/**
 * Destroys a queue.\n
 * Releases all memory from all nodes including header node.
 * source must be reinitialized to be used.
 *
 * @param source - pointer to a list
 */
void list_destroy(list_linked **source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to a list
 * @return - true if source is empty, false otherwise
 */
bool list_empty(const list_linked *source);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to a list
 * @return - the number of items in source
 */
int list_count(const list_linked *source);

/**
 * Appends a item to the rear of source.
 *
 * @param source - pointer to a list
 * @param item - the item to append
 * @return - true if item appended, false otherwise
 */
bool list_append(list_linked *source, const data_type *item);

/**
 * Prepends a item to the front of source.
 *
 * @param source - pointer to a list
 * @param item - the item to prepend
 * @return - true if item prepended, false otherwise
 */
bool list_prepend(list_linked *source, data_type *item);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to a list
 * @return the number of items in source
 */
int list_count(const list_linked *source);

/**
 * Inserts a item into source at location i. If i < 0, insert at index 0,
 * if i > source->count insert at index source->count.\n
 * Increments count.\n
 *
 * @param source - pointer to a list
 * @param i - the index to put the new item
 * @param item - the item to insert
 * @return - true if item inserted, false otherwise
 */
bool list_insert(list_linked *source, int i, data_type *item);

/**
 * Returns a copy of the item at the front of source. source is unchanged.
 *
 * @param source - pointer to a list
 * @param item - the item to peek
 * @return - true if item peeked, false otherwise (list is empty)
 */
bool list_peek(const list_linked *source, data_type *item);

/**
 * Removes and returns the item at index i from source.
 *
 * @param source - pointer to a list
 * @param item - a copy of the item removed
 * @param i - index of item to remove
 * @return - true if item is removed, false otherwise
 */
bool list_index_remove(list_linked *source, int i, data_type *item);

/**
 * Returns a copy of the first item matching key in source.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_find(const list_linked *source, const data_type *key, data_type *item);

/**
 * Removes and returns the first item matching key from source.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_remove(list_linked *source, const data_type *key, data_type *item);

/**
 * Removes and returns the first item in source. Returns false if source is empty.
 *
 * @param source - pointer to a list.
 * @param item - a copy of the item removed.
 * @return - true if item removed, false otherwise.
 */
bool list_remove_front(list_linked *source, data_type *item);

/**
 * Returns the index of the first occurrence of key in source. -1 if key not in source.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - index of the location of key in source
 */
int list_key_index(const list_linked *source, const data_type *key);

/**
 * Determines if key is in source.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - true if key in source, false otherwise
 */
bool list_key_contains(const list_linked *source, const data_type *key);

/**
 * Determines number of times key appears in source.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - number of times key appears in source
 */
int list_key_count(const list_linked *source, const data_type *key);

/**
 * Finds the maximum item in source.
 *
 * @param source - pointer to a list
 * @param item - pointer to the maximum item
 * @return - true if a maximum value is found, false otherwise (list is empty)
 */
bool list_max(const list_linked *source, data_type *item);

/**
 * Finds the minimum item in source.
 *
 * @param source - pointer to a list
 * @param item - pointer to the minimum item
 * @return - true if a minimum value is found, false otherwise (list is empty)
 */
bool list_min(const list_linked *source, data_type *item);

/**
 * Removes all duplicate items from source. Only the first copy of each item remains
 * in source.
 *
 * @param source - pointer to a list
 */
void list_clean(list_linked *source);

/**
 * Compares two lists for equality. Lists are equal if they contain the equivalent items
 * in the same order.
 *
 * @param source - the first list to compare
 * @param target - the second list to compare
 * @return - true if lists are identical, false otherwise
 */
bool list_equal(const list_linked *target, const list_linked *source);

/**
 * Combines the contents of two source lists into a target list. Items alternate.
 * Source lists are empty (not destroyed) when the function completes.
 * Moves nodes, not data.
 *
 * @param target - pointer to target list
 * @param source1 - pointer to first source list
 * @param source2 - pointer to second source list
 */
void list_combine(list_linked *target, list_linked *source1, list_linked *source2);

/**
 * Splits a source list alternately into two target lists. Items alternate.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to a list list
 */
void list_split_alt(list_linked *target1, list_linked *target2, list_linked *source);

/**
 * Splits a source list into two target lists at the middle of the source list.
 * If the source list is even in size, it is split evenly.
 * If the source list is odd in size, target1 gets the large half of source.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to a list list
 */
void list_split(list_linked *target1, list_linked *target2, list_linked *source);

/**
 * Splits a source list into two target lists based upon a key value.
 * target1 contains all values < key, target2 contains all values >= key.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to target1
 * @param target2 - pointer to target2
 * @param source - pointer to a list
 * @param key - item to split list with
 */
void list_split_key(list_linked *target1, list_linked *target2, list_linked *source, data_type *key);

/**
 * Copies contents of source to target. target is destroyed and reinitialized
 * if necessary.
 *
 * @param target - the list to copy to
 * @param source - the list to copy from
 * @return - true if source is copied to target, false otherwise
 */
bool list_copy(list_linked **target, const list_linked *source);

/**
 * Prints the items in source from front to rear.
 *
 * @param source - pointer to a list.
 */
void list_print(const list_linked *source);

#endif /* LIST_linked_H_ */
