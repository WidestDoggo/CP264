/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "stack_dynamic.h"
#include "queue_dynamic.h"
#include "pq_dynamic.h"
#include "list_dynamic.h"

#define TST "===========================================\n"
#define SEP "-------------------------------------------\n"

#define FOODS_FILE  "foods.txt"

int test_stack_generic(const data_type *values, int count) {
    printf(TST);
    printf("Testing stack_dynamic\n");
    printf(SEP);

    data_type item;
    char string[200];
    stack_dynamic source, target;

    printf("stack_initialize(&source, %d):\n", count - 2);

    if(!stack_initialize(&source, count - 2)) {
        perror("stack could not be initialized");
        return 1;
    }
    printf("stack_print(&source)\n");
    stack_print(&source);
    printf(SEP);
    printf("stack_empty(&source): %s\n", BOOL_STR(stack_empty(&source)));
    printf(SEP);

    for(int i = 0; i < count; i++) {
        data_string(string, sizeof string, &values[i]);
        printf("stack_push(&source, %s)\n", string);

        if(!stack_push(&source, &values[i])) {
            perror("push failed");
            return 1;
        }
    }
    printf("stack_print(&source)\n");
    stack_print(&source);
    printf(SEP);
    printf("stack_empty(&source): %s\n", BOOL_STR(stack_empty(&source)));
    printf(SEP);
    printf("stack_peek(&source, &item)\n");
    stack_peek(&source, &item);
    data_string(string, sizeof string, &item);
    printf("item: %s\n", string);
    printf(SEP);
    printf("stack_initialize(&target, %d):\n", count - 2);

    if(!stack_initialize(&target, count - 2)) {
        perror("stack could not be initialized");
        return 1;
    }
    printf("stack_copy(&target, &source)\n");
    stack_copy(&target, &source);
    printf("stack_print(&target)\n");
    stack_print(&target);
    printf(SEP);
    printf("stack_equal(&source, &target): %s\n", BOOL_STR(stack_equal(&source, &target)));
    printf("stack_pop(&target, &item)\n");
    stack_pop(&target, &item);
    printf("stack_equal(&source, &target): %s\n", BOOL_STR(stack_equal(&source, &target)));
    printf(SEP);

    while(!stack_empty(&source)) {
        printf("stack_pop(&source, &item)\n");
        stack_pop(&source, &item);
        data_string(string, sizeof string, &item);
        printf("  item: %s\n", string);
    }
    printf("\n");
    printf("stack_print(&source)\n");
    stack_print(&source);
    return 0;
}

int test_queue_generic(const data_type *values, int count) {
    printf(TST);
    printf("Testing queue_dynamic\n");
    printf(SEP);

    data_type item;
    char string[200];
    queue_dynamic source, target;

    printf("queue_initialize(&source, %d):\n", count - 2);

    if(!queue_initialize(&source, count - 2)) {
        perror("queue could not be initialized");
        return 1;
    }
    printf("queue_print(&source)\n");
    queue_print(&source);
    printf(SEP);
    printf("queue_empty(&source): %s\n", BOOL_STR(queue_empty(&source)));
    printf(SEP);

    for(int i = 0; i < count; i++) {
        data_string(string, sizeof string, &values[i]);
        printf("queue_insert(&source, %s)\n", string);

        if(!queue_insert(&source, &values[i])) {
            perror("insert failed");
            return 1;
        }
    }
    printf("queue_print(&source)\n");
    queue_print(&source);
    printf(SEP);
    printf("queue_empty(&source): %s\n", BOOL_STR(queue_empty(&source)));
    printf(SEP);
    printf("queue_peek(&source, &item)\n");
    queue_peek(&source, &item);
    data_string(string, sizeof string, &item);
    printf("item: %s\n", string);
    printf(SEP);

    printf("queue_initialize(&target, %d):\n", count - 2);

    if(!queue_initialize(&target, count - 2)) {
        perror("queue could not be initialized");
        return 1;
    }
    printf("queue_copy(&target, &source)\n");
    queue_copy(&target, &source);
    printf("queue_print(&target)\n");
    queue_print(&target);
    printf(SEP);
    printf("queue_equal(&target, &source): %s\n", BOOL_STR(queue_equal(&target, &source)));
    printf("queue_remove(&target, &item)\n");
    queue_remove(&target, &item);
    printf("queue_equal(&target, &source): %s\n", BOOL_STR(queue_equal(&target, &source)));
    printf(SEP);

    while(!queue_empty(&source)) {
        printf("queue_remove(&source, &item)\n");
        queue_remove(&source, &item);
        data_string(string, sizeof string, &item);
        printf("  item: %s\n", string);
    }
    printf("\n");
    printf("queue_print(&source)\n");
    queue_print(&source);

    return 0;
}

int test_pq_generic(const data_type *values, int count) {
    printf(TST);
    printf("Testing pq_dynamic\n");
    printf(SEP);

    data_type item;
    char string[200];
    pq_dynamic source, target;

    printf("pq_initialize(&source, %d):\n", count - 2);

    if(!pq_initialize(&source, count - 2)) {
        perror("pq could not be initialized");
        return 1;
    }
    printf("pq_print(&source)\n");
    pq_print(&source);
    printf(SEP);
    printf("pq_empty(&source): %s\n", BOOL_STR(pq_empty(&source)));
    printf(SEP);

    for(int i = 0; i < count; i++) {
        data_string(string, sizeof string, &values[i]);
        printf("pq_insert(&source, %s)\n", string);

        if(!pq_insert(&source, &values[i])) {
            perror("insert failed");
            return 1;
        }
    }
    printf("pq_print(&source)\n");
    pq_print(&source);
    printf(SEP);
    printf("pq_empty(&source): %s\n", BOOL_STR(pq_empty(&source)));
    printf(SEP);
    printf("pq_peek(&source, &item)\n");
    pq_peek(&source, &item);
    data_string(string, sizeof string, &item);
    printf("item: %s\n", string);
    printf(SEP);

    printf("pq_initialize(&target, %d):\n", count - 2);

    if(!pq_initialize(&target, count - 2)) {
        perror("pq could not be initialized");
        return 1;
    }
    printf("pq_copy(&target, &source)\n");
    pq_copy(&target, &source);
    printf("pq_print(&target)\n");
    pq_print(&target);
    printf(SEP);
    printf("pq_equal(&source, &target): %s\n", BOOL_STR(pq_equal(&source, &target)));
    printf("pq_remove(&target, &item)\n");
    pq_remove(&target, &item);
    printf("pq_equal(&source, &target): %s\n", BOOL_STR(pq_equal(&source, &target)));
    printf(SEP);

    while(!pq_empty(&source)) {
        printf("pq_remove(&source, &item)\n");
        pq_remove(&source, &item);
        data_string(string, sizeof string, &item);
        printf("  item: %s\n", string);
    }
    printf("\n");
    printf("pq_print(&source)\n");
    pq_print(&source);

    return 0;
}

int test_list_generic(const data_type *values, int count) {
    printf(TST);
    printf("Testing list_dynamic\n");
    printf(SEP);

    data_type item;
    data_type key;
    char string[200];
    list_dynamic source, target;

    printf("list_initialize(&source, %d):\n", count - 2);

    if(!list_initialize(&source, count - 2)) {
        perror("list could not be initialized");
        return 1;
    }
    printf("list_print(&source)\n");
    list_print(&source);
    printf(SEP);
    printf("list_empty(&source): %s\n", BOOL_STR(list_empty(&source)));
    printf(SEP);

    for(int i = 0; i < count; i++) {
        data_string(string, sizeof string, &values[i]);
        printf("list_append(&source, %s)\n", string);

        if(!list_append(&source, &values[i])) {
            perror("append failed");
            return 1;
        }
    }
    printf("list_print(&source)\n");
    list_print(&source);
    printf(SEP);

    printf("list_peek(&source, &item)\n");
    list_peek(&source, &item);
    data_string(string, sizeof string, &item);
    printf("item: %s\n", string);
    printf(SEP);

    printf("list_max(&source, &item)\n");
    list_max(&source, &item);
    data_string(string, sizeof string, &item);
    printf("max: %s\n", string);
    printf(SEP);

    printf("list_min(&source, &item)\n");
    list_min(&source, &item);
    data_string(string, sizeof string, &item);
    printf("min: %s\n", string);
    printf(SEP);

    data_copy(&key, &values[count / 2]);
    data_string(string, sizeof string, &key);
    printf("list_key_find(&source, %s, &item)\n", string);
    if(list_key_find(&source, &key, &item)) {
        data_string(string, sizeof string, &item);
        printf("found: %s\n", string);
    } else {
        printf("found: false\n");
    }
    printf(SEP);

    printf("list_initialize(&target, %d):\n", count - 2);

    if(!list_initialize(&target, count - 2)) {
        perror("list could not be initialized");
        return 1;
    }
    printf("list_copy(&target, &source)\n");
    list_copy(&target, &source);
    printf("list_print(&target)\n");
    list_print(&target);
    printf(SEP);
    printf("list_equal(&source, &target): %s\n", BOOL_STR(list_equal(&source, &target)));
    printf("list_index_remove(&target, 0, &item)\n");
    list_index_remove(&target, 0, &item);
    printf("list_equal(&source, &target): %s\n", BOOL_STR(list_equal(&source, &target)));
    printf(SEP);

    printf("list_key_remove(&source, key, &item)\n");
    list_key_remove(&source, &key, &item);
    data_string(string, sizeof string, &item);
    printf("removed: %s\n", string);
    printf("list_print(&source)\n");
    list_print(&source);

    return 0;
}

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

#ifdef USE_INT
    const data_type values[] = {{2}, {4}, {1}, {7}, {4}, {2}, {9}, {3}, {6}, {6}, {8}};
    int values_count = (int)(sizeof values / sizeof *values);
#endif

#ifdef USE_FOOD
    food_array foods;
    food_array_init(&foods);
    FILE *fp = fopen(FOODS_FILE, "r");
    foods_read(fp, &foods);
    fclose(fp);
    const data_type *values = foods.items;
    int values_count = foods.count;
#endif

    test_stack_generic(values, values_count);
    test_queue_generic(values, values_count);
    test_pq_generic(values, values_count);
    test_list_generic(values, values_count);
    return (0);
}