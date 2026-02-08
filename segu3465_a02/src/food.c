/** @file  food.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "food.h"

// ==============================================================================================
// Constants

/**
 * Defines an array of strings for possible origins.
 * const keyword means array and contents cannot be changed.
 * Requires:
 * extern const char *const ORIGINS[];
 * extern const int ORIGINS_COUNT;
 * in header file so all other files are aware these exist.
 */
const char *const ORIGINS[] = {"Canadian", "Chinese", "Indian", "Ethiopian", "Mexican", "Greek", "Japanese", "Italian",
        "American", "Scottish", "New Zealand", "English"};
// Calculates size of ORIGINS array.
const int ORIGINS_COUNT = sizeof ORIGINS / sizeof *ORIGINS;

// ==============================================================================================
// Functions

void food_init(food_struct *food, const char *const name, int origin, bool is_vegetarian, int calories) {

    // your code here

    return;
}

int food_compare(const food_struct *source, const food_struct *target) {

    // your code here

    return 0;
}

void food_copy(food_struct *target, const food_struct *source) {

    // your code here

    return;
}

int food_string(char *string, size_t size, const food_struct *food) {

    // your code here

    return 0;
}

int food_key(char *string, size_t size, const food_struct *food) {

    // your code here

    return 0;
}

int food_hash(const food_struct *source) {

    // your code here

    return 0;
}

int origins_menu(char *string, size_t size) {

    // your code here

    return 0;
}
