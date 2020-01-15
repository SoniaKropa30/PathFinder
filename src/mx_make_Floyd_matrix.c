#include "header.h"

static void init_D_M(t_app *app);
static void Floyd(t_app *app);

void mx_make_Floyd_matrix(t_app *app) {
    init_D_M(app);
    Floyd(app);
}

static void init_D_M(t_app *app) {
    app->D_M = malloc((app->SIZE * app->SIZE) * sizeof(int));
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = 0; j < app->SIZE; j++) {
            app->D_M[i * app->SIZE + j] = app->A_M[i * app->SIZE + j];
        }
    }
}

static void Floyd(t_app *app) {
    int * dis= app->D_M;
    int  size = app->SIZE;
    size_t x = 0;
    size_t y = 0;

    for (int k = 0; k < size; k ++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int ik = i * size + k;
                int kj = k * size + j;
                int ij = i * size + j;
                x = dis[ij];
                y = dis[ik] + dis[kj];
                if (y < x)
                    dis[ij] = dis[ik] + dis[kj];
            }
        }
    }
}

// if (dis[ik] + dis[kj] < dis[ij])
//     dis[ij] = dis[ik] + dis[kj];
