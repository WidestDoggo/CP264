/* queue_dynamic.c */
#include "queue_dynamic.h"

// ==============================================================================================
// Functions

bool queue_initialize(queue_dynamic *source, int capacity) {

    bool initialized = false;

    if(capacity < 1) {
        capacity = QUEUE_INIT_CAPACITY;
    }

    source->capacity = 0;
    source->count = 0;
    source->front = -1;
    source->rear = 0;
    source->items = malloc((size_t) capacity * sizeof *source->items);

    if(source->items != NULL) {
        source->capacity = capacity;
        initialized = true;
    }
    return initialized;
}

void queue_destroy(queue_dynamic *source) {

    free(source->items);
    source->items = NULL;
    source->capacity = 0;
    source->count = 0;
    source->front = -1;
    source->rear = 0;
    return;
}

bool queue_empty(const queue_dynamic *source) {

    return source->count == 0;
}

int queue_count(const queue_dynamic *source) {

    return source->count;
}

static bool queue_grow(queue_dynamic *source) {

    int new_capacity = 2 * source->capacity + 1;
    data_type *new_items = malloc((size_t) new_capacity * sizeof *new_items);

    if(new_items == NULL) {
        return false;
    }

    // Copy existing items to new array in queue order.
    for(int i = 0; i < source->count; i++) {
        int old_i = (source->front + i) % source->capacity;
        data_copy(&(new_items[i]), &(source->items[old_i]));
    }

    free(source->items);
    source->items = new_items;
    source->capacity = new_capacity;

    if(source->count == 0) {
        source->front = -1;
        source->rear = 0;
    } else {
        source->front = 0;
        source->rear = source->count;
    }
    return true;
}

bool queue_insert(queue_dynamic *source, const data_type *item) {

    if(source->count == source->capacity) {
        if(!queue_grow(source)) {
            return false;
        }
    }

    if(source->count == 0) {
        source->front = 0;
        source->rear = 0;
    }

    data_copy(&(source->items[source->rear]), item);
    source->rear = (source->rear + 1) % source->capacity;
    source->count += 1;
    return true;
}

bool queue_peek(const queue_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }
    data_copy(item, &(source->items[source->front]));
    return true;
}

bool queue_remove(queue_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }

    data_copy(item, &(source->items[source->front]));
    source->front = (source->front + 1) % source->capacity;
    source->count -= 1;

    if(source->count == 0) {
        source->front = -1;
        source->rear = 0;
    }
    return true;
}

bool queue_equal(const queue_dynamic *target, const queue_dynamic *source) {

    if(target->count != source->count) {
        return false;
    }

    for(int i = 0; i < source->count; i++) {
        int s_i = (source->front + i) % source->capacity;
        int t_i = (target->front + i) % target->capacity;

        if(data_compare(&(source->items[s_i]), &(target->items[t_i])) != 0) {
            return false;
        }
    }
    return true;
}

bool queue_copy(queue_dynamic *target, const queue_dynamic *source) {

    queue_destroy(target);

    if(!queue_initialize(target, source->capacity)) {
        return false;
    }

    target->count = source->count;

    if(source->count == 0) {
        target->front = -1;
        target->rear = 0;
    } else {
        target->front = 0;
        target->rear = source->count;

        for(int i = 0; i < source->count; i++) {
            int s_i = (source->front + i) % source->capacity;
            data_copy(&(target->items[i]), &(source->items[s_i]));
        }
    }
    return true;
}

void queue_print(const queue_dynamic *source) {
    char string[200];
    // Walk through queue from front to rear using indexes.
    printf("capacity: %d\n", source->capacity);
    printf("count: %d\n", source->count);
    printf("front: %d\n", source->front);
    printf("rear: %d\n", source->rear);
    printf("  values:\n");

    int temp = source->front;

    for(int i = 0; i < source->count; i++) {
        data_string(string, sizeof string, &(source->items[temp]));
        printf("%s\n", string);
        temp = (temp + 1) % source->capacity;
    }
    return;
}