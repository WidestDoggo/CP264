/** @file  main.c
 * -------------------------------------
 * @author your name, your id, your email
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data.h"
#include "pq_linked.h"
#include "list_linked.h"

#define TST "===========================================\n"
#define SEP "-------------------------------------------\n"

#define FOODS_FILE  "foods.txt"

int test_pq_generic(const data_type *values, int count) {
    printf(TST);
    printf("Testing pq_linked\n");
    printf(SEP);

    data_type item;
    char string[200];
    pq_linked *source = pq_initialize();
    pq_linked *target = pq_initialize();

    printf("source = pq_initialize():\n");
    printf("pq_print(source)\n");
    pq_print(source);
    printf(SEP);
    printf("pq_empty(source): %s\n", BOOL_STR(pq_empty(source)));
    printf(SEP);

    for(int i = 0; i < count; i++) {
        data_string(string, sizeof string, &values[i]);
        printf("pq_insert(source, %s)\n", string);

        if(!pq_insert(source, &values[i])) {
            perror("insert failed");
            return 1;
        }
    }
    printf("pq_print(source)\n");
    pq_print(source);
    printf(SEP);
    printf("pq_empty(source): %s\n", BOOL_STR(pq_empty(source)));
    printf(SEP);
    printf("pq_peek(source, &item)\n");
    pq_peek(source, &item);
    data_string(string, sizeof string, &item);
    printf("item: %s\n", string);
    printf(SEP);
    printf("pq_initialize(&target, %d):\n", count - 2);

    if(!pq_initialize(&target, count - 2)) {
        perror("priority queue could not be initialized");
        return 1;
    }
    printf("pq_copy(&target, source)\n");
    pq_copy(&target, source);
    printf("pq_print(target)\n");
    pq_print(target);
    printf(SEP);
    printf("pq_equal(source, &target): %s\n", BOOL_STR(pq_equal(source, target)));
    printf("pq_remove(&target, &item)\n");
    pq_remove(target, &item);
    printf("pq_equal(source, &target): %s\n", BOOL_STR(pq_equal(source, target)));
    printf(SEP);

    while(!pq_empty(source)) {
        printf("pq_remove(source, &item)\n");
        pq_remove(source, &item);
        data_string(string, sizeof string, &item);
        printf("  item: %s\n", string);
    }
    printf("\n");
    printf("pq_print(source)\n");
    pq_print(source);
    printf(SEP);
    printf("pq_destroy(&source)\n");
    pq_destroy(&source);
    return 0;
}

int test_list_generic(const data_type *values, int count) {
    printf(TST);
    printf("Testing list_linked\n");
    printf(SEP);

    data_type item;
    char string[200];
    list_linked *source = list_initialize();
//    list_linked *target1 = list_initialize();
//    list_linked *target2 = list_initialize();

    printf("list_linked *source = list_initialize():\n");

    if(!source) {
        perror("list could not be initialized");
        return 1;
    }
    printf("list_print(source)\n");
    list_print(source);
    printf(SEP);
    printf("list_empty(source): %s\n", BOOL_STR(list_empty(source)));
    printf(SEP);

    for(int i = 0; i < count; i++) {
        data_string(string, sizeof string, &values[i]);
        printf("list_append(source, %s)\n", string);

        if(!list_append(source, &values[i])) {
            perror("append failed");
            return 1;
        }
    }
    printf("list_print(&source)\n");
    list_print(source);
    printf(SEP);
    printf("list_empty(source): %s\n", BOOL_STR(list_empty(source)));
    printf(SEP);
    printf("list_peek(&source, &item)\n");
    list_peek(source, &item);
    data_string(string, sizeof string, &item);
    printf("item: %s\n", string);
    printf(SEP);

    // other tests here

    printf("\nother tests here\n\n");
    printf(SEP);
    printf("list_destroy(&source)\n");
    list_destroy(&source);
    return 0;
}

/**
 * Change commenting here and in data.h in order to use a given data type.
 *
 * @param argc - unused
 * @param argv - unused
 * @return
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

#ifdef USE_INT
    // integer test values
    const data_type values[] = {{2}, {4}, {1}, {7}, {4}, {2}, {9}, {3}, {6}, {6}, {8}};
    int values_count = sizeof values / sizeof *values;
#endif

#ifdef USE_FOOD
    // food test values
    food_array foods;
    food_array_init(&foods);
    FILE *fp = fopen(FOODS_FILE, "r");
    foods_read(fp, &foods);
    fclose(fp);
    const data_type *values = foods.items;
    int values_count = foods.count;
#endif

#ifdef USE_STRING
    // integer test values
    const data_type values[] = {{"dog"}, {"cat"}, {"rat"}, {"bird"}, {"pig"}};
    int values_count = sizeof values / sizeof *values;
#endif

    test_pq_generic(values, values_count);
    test_list_generic(values, values_count);
    return 0;
}
