/* pq_dynamic.c */
#include "pq_dynamic.h"

// ==============================================================================================
// Functions

bool pq_initialize(pq_dynamic *source, int capacity) {

    bool initialized = false;

    if(capacity < 1) {
        capacity = PQ_INIT_CAPACITY;
    }

    source->capacity = 0;
    source->count = 0;
    source->first = -1;
    source->items = malloc((size_t) capacity * sizeof *source->items);

    if(source->items != NULL) {
        source->capacity = capacity;
        initialized = true;
    }
    return initialized;
}

void pq_destroy(pq_dynamic *source) {

    free(source->items);
    source->items = NULL;
    source->capacity = 0;
    source->count = 0;
    source->first = -1;
    return;
}

bool pq_empty(const pq_dynamic *source) {

    return source->count == 0;
}

int pq_count(const pq_dynamic *source) {

    return source->count;
}

static void pq_update_first(pq_dynamic *source) {

    if(source->count == 0) {
        source->first = -1;
        return;
    }

    int best = 0;

    for(int i = 1; i < source->count; i++) {
        // Smaller value == higher priority.
        if(data_compare(&(source->items[i]), &(source->items[best])) < 0) {
            best = i;
        }
    }
    source->first = best;
}

bool pq_insert(pq_dynamic *source, const data_type *item) {

    if(source->count == source->capacity) {
        int new_capacity = 2 * source->capacity + 1;
        data_type *ptr = realloc(source->items, (size_t) new_capacity * sizeof *source->items);

        if(ptr == NULL) {
            return false;
        }
        source->items = ptr;
        source->capacity = new_capacity;
    }

    data_copy(&(source->items[source->count]), item);

    if(source->first == -1) {
        source->first = 0;
    } else {
        // Smaller value == higher priority.
        if(data_compare(item, &(source->items[source->first])) < 0) {
            source->first = source->count;
        }
    }

    source->count += 1;
    return true;
}

bool pq_peek(const pq_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }

    data_copy(item, &(source->items[source->first]));
    return true;
}

bool pq_remove(pq_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }

    data_copy(item, &(source->items[source->first]));

    // Move last element into the removed spot.
    int last = source->count - 1;
    source->items[source->first] = source->items[last];
    source->count -= 1;

    pq_update_first(source);
    return true;
}

bool pq_equal(const pq_dynamic *source, const pq_dynamic *target) {

    if(source->count != target->count) {
        return false;
    }

    for(int i = 0; i < source->count; i++) {
        if(data_compare(&(source->items[i]), &(target->items[i])) != 0) {
            return false;
        }
    }
    return true;
}

bool pq_copy(pq_dynamic *target, const pq_dynamic *source) {

    pq_destroy(target);

    if(!pq_initialize(target, source->capacity)) {
        return false;
    }

    target->count = source->count;
    target->first = source->first;

    for(int i = 0; i < source->count; i++) {
        data_copy(&(target->items[i]), &(source->items[i]));
    }
    return true;
}

void pq_print(const pq_dynamic *source) {
    char string[200];
    printf("capacity: %d\n", source->capacity);
    printf("count: %d\n", source->count);
    printf("first: %d\n", source->first);
    printf("  values:\n");
    for(int i = 0; i < source->count; i++) {
        data_string(string, sizeof string, &(source->items[i]));
        printf("%s\n", string);
    }
    return;
}