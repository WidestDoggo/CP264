/** @file  main.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-09-01
 *
 * These tests are not exhaustive. Feel free to add or adjust
 * tests to meet requirements.
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "food_utilities.h"

// ==============================================================================================
// Definitions

#define TST "===========================================\n"
#define SEP "-------------------------------------------\n"

#define ORIGIN_1 7
#define VEGETARIAN_1 false
#define CALORIES_1 650
#define ORIGIN_2 6
#define VEGETARIAN_2 false
#define CALORIES_2 600

#define NAME_1  "pizza"
#define NAME_2  "chirashi don"
#define FOOD  "chirashi don|6|false|600"
#define FOODS_FILE  "foods.txt"
#define ONE_FOOD_FILE  "one_food.txt"
#define ALL_FOODS_FILE  "all_foods.txt"

// ==============================================================================================
// Test Functions

static void test_food() {
    // Define test variables
    char string[LINE_LENGTH];
    food_struct source;
    food_struct target;

    printf(TST);
    printf("Test food\n\n");

    printf(SEP);
    printf("Test: origins_menu()\n\n");
    origins_menu(string, sizeof string);
    printf("%s\n", string);

    printf(SEP);
    printf("Test: food_init(&source, \"%s\", %d, %s, %d)\n\n", NAME_1, ORIGIN_1, BOOL_STR(VEGETARIAN_1), CALORIES_1);
    food_init(&source, NAME_1, ORIGIN_1, VEGETARIAN_1, CALORIES_1);

    printf(SEP);
    printf("Test: food_string(source):\n\n");
    food_string(string, LINE_LENGTH, &source);
    printf("source:\n%s\n", string);

    printf(SEP);
    printf("Test: food_copy(&target, &source):\n\n");
    food_copy(&target, &source);
    food_string(string, LINE_LENGTH, &target);
    printf("target:\n%s\n", string);

    printf(SEP);
    printf("Test: food_init(&target, \"%s\", %d, %s, %d)\n\n", NAME_2, ORIGIN_2, BOOL_STR(VEGETARIAN_2), CALORIES_2);
    food_init(&target, NAME_2, ORIGIN_2, VEGETARIAN_2, CALORIES_2);
    food_string(string, LINE_LENGTH, &target);
    printf("target:\n%s\n", string);
    printf("Test: result = food_compare(&source, &source):\n");
    int result = food_compare(&source, &source);
    printf("result: %d\n", result);
    printf("Test: result = food_compare(&source, &target):\n");
    result = food_compare(&source, &target);
    printf("result: %d\n", result);
    printf("Test: result = food_compare(&target, &source):\n");
    result = food_compare(&target, &source);
    printf("result: %d\n", result);

    printf(SEP);
    printf("Test: food_key(&source):\n\n");
    food_key(string, LINE_LENGTH, &source);
    printf("%s\n", string);

    printf(SEP);
    printf("Test: food_hash(&source):\n\n");
    int hash = food_hash(&source);
    printf("hash: %d\n\n", hash);
}

static void test_food_utilities() {
    // Define test variables
    char string[LINE_LENGTH];
    food_struct source;
    food_array all_foods;
    food_array_init(&all_foods);
    food_array veggie;
    food_array_init(&veggie);
    food_array origins;
    food_array_init(&origins);
    int origin = 0;

    printf(TST);
    printf("Test food_utilities\n\n");

    printf(SEP);
    printf("Test: food_read(&source, \"%s\"):\n\n", FOOD);
    food_read(&source, FOOD);
    food_string(string, LINE_LENGTH, &source);
    printf("source:\n%s\n", string);

    printf(SEP);
    printf("Test: foods_read(fp, &all_foods):\n(file: \"%s\")\n\n", FOODS_FILE);
    FILE *fp = fopen(FOODS_FILE, "r");
    foods_read(fp, &all_foods);
    fclose(fp);
    printf("all_foods (%d):\n\n", all_foods.count);
    for(int i = 0; i < all_foods.count; i++) {
        food_string(string, LINE_LENGTH, &all_foods.items[i]);
        printf("%s\n", string);
    }

    printf(SEP);
    printf("Test: foods_get_vegetarian(all_foods, &veggie):\n\n");
    foods_get_vegetarian(&all_foods, &veggie);
    printf("veggie:\n\n");
    for(int i = 0; i < veggie.count; i++) {
        food_string(string, LINE_LENGTH, &veggie.items[i]);
        printf("%s\n", string);
    }

    printf(SEP);
    printf("Test: foods_get_origin(all_foods, origins, %d):\n", origin);
    printf("(origin: %d = \"%s\")\n\n", origin, ORIGINS[origin]);
    foods_get_origin(&all_foods, &origins, origin);
    printf("origins:\n\n");
    for(int i = 0; i < origins.count; i++) {
        food_string(string, LINE_LENGTH, &origins.items[i]);
        printf("%s\n", string);
    }
    printf(SEP);
    printf("Test: food_write(fp, &source)\n(file: \"%s\")\n\n", ONE_FOOD_FILE);
    fp = fopen(ONE_FOOD_FILE, "w");
    food_write(fp, &source);
    fclose(fp);

    printf(SEP);
    printf("Test: foods_write(fp, all_foods)\n(file: \"%s\")\n\n", ALL_FOODS_FILE);
    fp = fopen(ALL_FOODS_FILE, "w");
    foods_write(fp, &all_foods);
    fclose(fp);

    printf(SEP);
    printf("Test: food_get(&source):\n\n");
    food_get(&source);
    printf("\n");
    food_string(string, LINE_LENGTH, &source);
    printf("%s\n", string);

}

// ==============================================================================================
// main Function

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    test_food();
    test_food_utilities();
    return (0);
}
