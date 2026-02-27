/** @file  queue_linked.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
//==================================================================================
// Includes
#include "queue_linked.h"

//==================================================================================
// Local Helper Functions

static queue_node* queue_node_create(const data_type *item) {
    queue_node *node = (queue_node*) malloc(sizeof *node);

    if(node != NULL) {
        data_copy(&node->item, item);
        node->next = NULL;
    }
    return node;
}

static void queue_clear(queue_linked *source) {
    if(source == NULL) {
        return;
    }

    queue_node *current = source->front;

    while(current != NULL) {
        queue_node *next = current->next;
        /* no data_free/data_destroy here */
        free(current);
        current = next;
    }

    source->front = NULL;
    source->rear  = NULL;
    source->count = 0;
}

static bool queue_move_front_node(queue_linked *target, queue_linked *source) {
    if(source == NULL || source->front == NULL) {
        return false;
    }

    queue_node *node = source->front;
    source->front = node->next;

    if(source->front == NULL) {
        source->rear = NULL;
    }

    node->next = NULL;
    source->count--;

    if(target->rear == NULL) {
        target->front = node;
        target->rear = node;
    } else {
        target->rear->next = node;
        target->rear = node;
    }
    target->count++;

    return true;
}

//==================================================================================
// Functions

queue_linked* queue_initialize() {

    queue_linked *q = (queue_linked*) malloc(sizeof *q);

    if(q != NULL) {
        q->front = NULL;
        q->rear = NULL;
        q->count = 0;
    }

    return q;
}

void queue_destroy(queue_linked **source) {

    if(source == NULL || *source == NULL) {
        return;
    }

    queue_clear(*source);
    free(*source);
    *source = NULL;

    return;
}

bool queue_empty(const queue_linked *source) {

    return (source == NULL || source->count == 0);
}

int queue_count(const queue_linked *source) {

    return (source == NULL) ? 0 : source->count;
}

bool queue_insert(queue_linked *source, const data_type *item) {

    if(source == NULL || item == NULL) {
        return false;
    }

    queue_node *node = queue_node_create(item);

    if(node == NULL) {
        return false;
    }

    if(source->rear == NULL) {
        source->front = node;
        source->rear = node;
    } else {
        source->rear->next = node;
        source->rear = node;
    }

    source->count++;
    return true;
}

bool queue_peek(const queue_linked *source, data_type *item) {

    if(source == NULL || item == NULL || source->front == NULL) {
        return false;
    }

    data_copy(item, &source->front->item);
    return true;
}

bool queue_remove(queue_linked *source, data_type *item) {

    if(source == NULL || item == NULL || source->front == NULL) {
        return false;
    }

    queue_node *node = source->front;
    data_copy(item, &node->item);

    source->front = node->next;

    if(source->front == NULL) {
        source->rear = NULL;
    }

    source->count--;

    free(node);

    return true;
}

bool queue_equal(const queue_linked *source, const queue_linked *target) {

    if(source == NULL || target == NULL) {
        return (source == target);
    }

    if(source->count != target->count) {
        return false;
    }

    queue_node *s = source->front;
    queue_node *t = target->front;

    while(s != NULL && t != NULL) {
        if(data_compare(&s->item, &t->item) != 0) {
            return false;
        }
        s = s->next;
        t = t->next;
    }

    return (s == NULL && t == NULL);
}

bool queue_copy(queue_linked **target, const queue_linked *source) {

    if(target == NULL || source == NULL) {
        return false;
    }

    if(*target == NULL) {
        *target = queue_initialize();
        if(*target == NULL) {
            return false;
        }
    } else {
        queue_clear(*target);
    }

    queue_node *current = source->front;

    while(current != NULL) {
        if(!queue_insert(*target, &current->item)) {
            queue_clear(*target);
            return false;
        }
        current = current->next;
    }

    return true;
}

void queue_append(queue_linked *target, queue_linked *source) {

    if(target == NULL || source == NULL || source->front == NULL) {
        return;
    }

    if(target->rear == NULL) {
        target->front = source->front;
        target->rear = source->rear;
    } else {
        target->rear->next = source->front;
        target->rear = source->rear;
    }

    target->count += source->count;

    source->front = NULL;
    source->rear = NULL;
    source->count = 0;

    return;
}

void queue_combine(queue_linked *target, queue_linked *source1, queue_linked *source2) {

    if(target == NULL || source1 == NULL || source2 == NULL) {
        return;
    }

    queue_clear(target);

    while(source1->front != NULL || source2->front != NULL) {

        if(source1->front != NULL) {
            queue_move_front_node(target, source1);
        }

        if(source2->front != NULL) {
            queue_move_front_node(target, source2);
        }
    }

    return;
}

void queue_split_alt(queue_linked *target1, queue_linked *target2, queue_linked *source) {

    if(target1 == NULL || target2 == NULL || source == NULL) {
        return;
    }

    queue_clear(target1);
    queue_clear(target2);

    bool to_first = true;

    while(source->front != NULL) {
        if(to_first) {
            queue_move_front_node(target1, source);
        } else {
            queue_move_front_node(target2, source);
        }
        to_first = !to_first;
    }

    return;
}

void queue_print(const queue_linked *source) {
    char string[200];
    queue_node *current = source->front;

    while(current != NULL) {
        data_string(string, sizeof string, &current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}