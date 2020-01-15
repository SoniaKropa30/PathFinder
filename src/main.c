#include "header.h"

int main(int argc, char *argv[]) {
    t_app *app = malloc(sizeof(t_app));

    mx_init(argc, argv, app);
    mx_make_Floyd_matrix(app);
    mx_restore_all_path(app);
    mx_free_all(app);
    mx_printchar('\n');
    return 0;
}

