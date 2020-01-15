#include "header.h"

static int city_index(char *element, t_app *app);

void mx_matrix_index(t_app *app, char * isl_1, char * isl_2, int dist) {
        int i = city_index(isl_1, app);
        int j = city_index(isl_2, app);
        mx_push_in_AM(app, dist, i, j);
}

static int city_index(char *element, t_app *app) {
    for(int i = 0; i < app->SIZE; i++) {
        if(mx_strcmp(element, app->city[i]) == 0)
            return i;
    }
    return -1;
}


