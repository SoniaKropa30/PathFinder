#include "header.h"
static void city_push_element(char *element, t_app *app);

void mx_city_push(char *isl_1, char * isl_2, t_app *app) {
    city_push_element(isl_1, app);
    city_push_element(isl_2, app);
}

static void city_push_element(char *element, t_app *app) {
    int i = 0;

    for (; i < app->SIZE; i++) {
        if (app->city[i] == NULL)
            break;
        if (mx_strcmp(app->city[i], element) == 0)
            return;
    }
    if (i < app->SIZE)
        app->city[i] = mx_strdup(element);
    else
        mx_print_all_error (INVALID_NUMBER_OF_ISLANDS, app);
}

