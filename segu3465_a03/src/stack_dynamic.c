/** @file  stack_dynamic.c
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "stack_dynamic.h"

// ==============================================================================================
// Functions

bool stack_initialize(stack_dynamic *source, int capacity) {
    bool initialized = false;
    // initialize top to invalid index for empty stack
    source->top = -1;
    // allocate memory to items array
    source->items = malloc(capacity * sizeof *source->items);

    if(source->items != NULL) {
        // memory allocated - update capacity
        source->capacity = capacity;
        initialized = true;
    } else {
        // memory allocation failed
        source->capacity = 0;
    }
    return initialized;
}

void stack_destroy(stack_dynamic *source) {
    // release memory from items array
    free(source->items);
    // set items to NULL to avoid accessing non-allocated memory
    source->items = NULL;
    // clear remaining fields
    source->capacity = 0;
    source->top = -1;
    return;
}

bool stack_empty(const stack_dynamic *source) {
    return source->top == -1;
}

bool stack_push(stack_dynamic *source, const data_type *item) {
    bool pushed = true;

    if(source->top == (source->capacity - 1)) {
        // increase the capacity if required
        int capacity = source->capacity * 2 + 1;
        data_type *ptr = realloc(source->items, capacity * sizeof *source->items);

        if(ptr == NULL) {
            // memory was not allocated
            pushed = false;
        } else {
            // extra memory was allocated, update items and capacity
            source->items = ptr;
            source->capacity = capacity;
        }
    }
    if(pushed) {
        source->top += 1;
        // append the new data to items
        data_copy(&(source->items[source->top]), item);
    }
    return pushed;
}

bool stack_peek(const stack_dynamic *source, data_type *item) {
    bool peeked = false;

    if(source->top > -1) {
        // copy top of stack to item
        data_copy(item, &(source->items[source->top]));
        peeked = true;
    }
    return peeked;
}

// Returns and removes the item on the top of a stack.
bool stack_pop(stack_dynamic *source, data_type *item) {
    bool popped = false;

    if(source->top > -1) {
        // item removed from top of stack - copy not required
        *item = source->items[source->top];
        source->top--;
        popped = true;
    }
    return popped;
}

bool stack_equal(const stack_dynamic *source, const stack_dynamic *target) {
    bool equals = false;

    if(source->top == target->top) {
        int i = 0;

        while((i <= source->top) && (data_compare(&source->items[i], &target->items[i]) == 0)) {
            i++;
        }
        // were all values in stacks compared?
        equals = (i == (source->top + 1));
    }
    return equals;
}

bool stack_copy(stack_dynamic *target, const stack_dynamic *source) {
    // clear existing stack
    stack_destroy(target);
    // initialize target stack
    bool copied = stack_initialize(target, source->capacity);

    if(copied) {
        target->top = source->top;

        for(int i = 0; i <= source->top; i++) {
            data_copy(&(target->items[i]), &(source->items[i]));
        }
    }
    return copied;
}

void stack_print(const stack_dynamic *source) {
    char string[200];
    printf("capacity: %d\n", source->capacity);
    printf("top: %d\n", source->top);
    printf("  values:\n");
    // Walk through stack from top to bottom using indexes.
    for(int i = source->top; i > -1; i--) {
        data_string(string, sizeof string, &(source->items[i]));
        printf("%s\n", string);
    }
    return;
}
