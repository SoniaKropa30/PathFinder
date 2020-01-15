#include "header.h"

void mx_push_in_stack(t_stack *st, int element) {
    if (st->size < st->max_size) {
        st->size++;
        st->path[st->size] = element;
    }
}

