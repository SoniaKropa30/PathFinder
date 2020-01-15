#include "header.h"

static void mx_init_stack(t_stack **st, t_app *app, int i, int j);
static void mx_helper_restor(t_app *app, t_stack *st);
static void restore_from_to(t_app *app, int i, int j);
static bool is_next( t_app *app, t_stack *st, int next);

void mx_restore_all_path(t_app *app) {
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = i + 1; j < app->SIZE; j++) {
            restore_from_to(app, i, j);
        }
    }
}

static void mx_init_stack(t_stack **st, t_app *app, int i, int j) {
    *st = malloc(sizeof(t_stack));
    if ((*st) == NULL)
        exit(1);

    (*st)->max_size = app->SIZE;
    (*st)->path = malloc((*st)->max_size * sizeof(int) + 1);
    (*st)->path[1] = i;
    (*st)->path[0] = j;
    (*st)->size = 1;
}

static bool is_next( t_app *app, t_stack *st, int next) {
    int *A_M = app->A_M;
    int *D_M = app->D_M;
    int size = app->SIZE;
    int i = mx_top_from_stack(st);
    int j = st->path[0];

    if (i != next) {
        if (D_M[i * size + j] - A_M[i * size + next] == D_M[next * size + j])
            return true;
    }
    return false;
}

static void mx_helper_restor(t_app *app, t_stack *st) {
    if (mx_top_from_stack(st) == st->path[0]) {
        mx_print_path(app, st);
        return;
    }
    else {
        for (int next = 0; next < app->SIZE; next++) {
            if (is_next(app, st, next)) {
                mx_push_in_stack(st, next);
                mx_helper_restor(app, st);
                mx_pop_from_stack(st);
            }
        }
    }
}

static void restore_from_to(t_app *app, int i, int j) {
    t_stack *st = NULL;
    mx_init_stack(&st, app, i, j);
    mx_helper_restor(app, st);
    free(st->path);
    free(st);
}
