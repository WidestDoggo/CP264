/* list_dynamic.c */
#include "list_dynamic.h"

// ==============================================================================================
// Functions

bool list_initialize(list_dynamic *source, int capacity) {

    bool initialized = false;

    if(capacity < 1) {
        capacity = LIST_INIT_CAPACITY;
    }

    source->capacity = 0;
    source->count = 0;
    source->items = malloc((size_t) capacity * sizeof *source->items);

    if(source->items != NULL) {
        source->capacity = capacity;
        initialized = true;
    }
    return initialized;
}

void list_destroy(list_dynamic *source) {

    free(source->items);
    source->items = NULL;
    source->capacity = 0;
    source->count = 0;
    return;
}

bool list_empty(const list_dynamic *source) {

    return source->count == 0;
}

int list_count(const list_dynamic *source) {

    return source->count;
}

static bool list_grow(list_dynamic *source) {

    int new_capacity = 2 * source->capacity + 1;
    data_type *ptr = realloc(source->items, (size_t) new_capacity * sizeof *source->items);

    if(ptr == NULL) {
        return false;
    }

    source->items = ptr;
    source->capacity = new_capacity;
    return true;
}

bool list_append(list_dynamic *source, const data_type *item) {

    if(source->count == source->capacity) {
        if(!list_grow(source)) {
            return false;
        }
    }

    data_copy(&(source->items[source->count]), item);
    source->count += 1;
    return true;
}

bool list_insert(list_dynamic *source, const data_type *item, int i) {

    if(i < 0) {
        i = 0;
    } else if(i > source->count) {
        i = source->count;
    }

    if(source->count == source->capacity) {
        if(!list_grow(source)) {
            return false;
        }
    }

    for(int j = source->count; j > i; j--) {
        source->items[j] = source->items[j - 1];
    }

    data_copy(&(source->items[i]), item);
    source->count += 1;
    return true;
}

bool list_peek(const list_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }

    data_copy(item, &(source->items[0]));
    return true;
}

bool list_index_remove(list_dynamic *source, int i, data_type *item) {

    if(i < 0 || i >= source->count) {
        return false;
    }

    data_copy(item, &(source->items[i]));

    for(int j = i; j < source->count - 1; j++) {
        source->items[j] = source->items[j + 1];
    }

    source->count -= 1;
    return true;
}

bool list_key_find(const list_dynamic *source, const data_type *key, data_type *item) {

    for(int i = 0; i < source->count; i++) {
        if(data_compare(&(source->items[i]), key) == 0) {
            data_copy(item, &(source->items[i]));
            return true;
        }
    }
    return false;
}

int list_key_index(const list_dynamic *source, const data_type *key) {

    for(int i = 0; i < source->count; i++) {
        if(data_compare(&(source->items[i]), key) == 0) {
            return i;
        }
    }
    return -1;
}

bool list_key_contains(const list_dynamic *source, const data_type *key) {

    return list_key_index(source, key) != -1;
}

int list_key_count(const list_dynamic *source, const data_type *key) {

    int count = 0;

    for(int i = 0; i < source->count; i++) {
        if(data_compare(&(source->items[i]), key) == 0) {
            count += 1;
        }
    }
    return count;
}

bool list_key_remove(list_dynamic *source, const data_type *key, data_type *item) {

    int i = list_key_index(source, key);
    return list_index_remove(source, i, item);
}

bool list_max(const list_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }

    int best = 0;

    for(int i = 1; i < source->count; i++) {
        if(data_compare(&(source->items[i]), &(source->items[best])) > 0) {
            best = i;
        }
    }

    data_copy(item, &(source->items[best]));
    return true;
}

bool list_min(const list_dynamic *source, data_type *item) {

    if(source->count == 0) {
        return false;
    }

    int best = 0;

    for(int i = 1; i < source->count; i++) {
        if(data_compare(&(source->items[i]), &(source->items[best])) < 0) {
            best = i;
        }
    }

    data_copy(item, &(source->items[best]));
    return true;
}

bool list_equal(const list_dynamic *source, const list_dynamic *target) {

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

bool list_copy(list_dynamic *target, const list_dynamic *source) {

    list_destroy(target);

    if(!list_initialize(target, source->capacity)) {
        return false;
    }

    target->count = source->count;

    for(int i = 0; i < source->count; i++) {
        data_copy(&(target->items[i]), &(source->items[i]));
    }

    return true;
}

void list_print(const list_dynamic *source) {
    char string[200];
    printf("capacity: %d\n", source->capacity);
    printf("count: %d\n", source->count);
    printf("  values:\n");
    for(int i = 0; i < source->count; i++) {
        data_string(string, sizeof string, &(source->items[i]));
        printf("%s\n", string);
    }
    return;
}