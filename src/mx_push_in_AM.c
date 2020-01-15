#include "header.h"

void mx_push_in_AM(t_app *app, int dist, int i, int j) {
    app->A_M[i * app->SIZE + j] = dist;
    app->A_M[j * app->SIZE + i] = dist;
}

