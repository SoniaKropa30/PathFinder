#include "header.h"

static void init_A_M(t_app *app);

void mx_city_init(t_app *app) {
    app->city = malloc(app->SIZE * sizeof(char *) + 1);
    if (app->city == NULL)
        exit(1);
    for (int i = 0; i <= app->SIZE; i++) {
        app->city[i] = NULL;
    }
    init_A_M(app);
}

static void init_A_M(t_app *app) {
    app->A_M = malloc((app->SIZE * app->SIZE) * sizeof(int));
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = 0; j < app->SIZE; j++) {
            if (i == j)
                app->A_M[i * app->SIZE + j] = 0;
            else
                app->A_M[i * app->SIZE + j] = 2147483647;
        }
    }
}
