#include "header.h"

static void del_matrix(int *x);

void mx_free_all(t_app *app) {
    mx_del_strarr(&(app->city));
    mx_del_strarr(&(app->pars_lines_arr));
    mx_strdel(&(app->file_to_str));
    del_matrix(app->A_M);
    del_matrix(app->D_M);
}

static void del_matrix(int *x) {
    if (x != NULL)
        free(x);
}
