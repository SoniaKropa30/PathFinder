#include "header.h"

static char *take_element_in_city(int i, t_app *app);
static void print_path(t_app *app, t_stack *st);
static void print_route(t_app *app, t_stack *st);
static void print_dist(t_app *app, t_stack *st);

void mx_print_path(t_app *app, t_stack *st) {
    static bool first_line = true;
    if (first_line) {
        first_line = false;
    }
    else {
        mx_printstr("\n");
    }
    mx_print_line();
    mx_printstr("\n");
    print_path(app, st);
    print_route(app, st);
    print_dist(app, st);
    mx_printstr("\n");
    mx_print_line();
}

static char *take_element_in_city(int i, t_app *app) {
    return app->city[i];
}

static void print_path(t_app *app, t_stack *st) {
    mx_printstr("Path: ");
    mx_printstr(take_element_in_city (st->path[1], app));
    mx_printstr(" -> ");
    mx_printstr(take_element_in_city(st->path[0], app));
    mx_printstr("\n");
}

static void print_route(t_app *app, t_stack *st) {
    mx_printstr("Route: ");
    for (int i = 1; i < st->size; i++) {
        mx_printstr(take_element_in_city(st->path[i], app));
        mx_printstr(" -> ");
    }
    mx_printstr(take_element_in_city(st->path[st->size], app));
    mx_printstr("\n");
}

static void print_dist(t_app *app, t_stack *st) {
    int total_dist = 0;
    int dist = 0;

    int n = st->size;
    mx_printstr("Distance: ");

    if (n == 2)
        mx_printint(app->D_M[st->path[0] * app->SIZE + st->path[1]]);
    else {
        for (int i = 1; i < n; i++) {
            dist = app->A_M[st->path[i] * app->SIZE + st->path[i + 1]];
            total_dist += dist;
            mx_printint(dist);
            (i + 1 < n) ? mx_printstr(" + ") : mx_printstr("");
        }
        mx_printstr(" = ");
        mx_printint(total_dist);
    
    }
}
