#include "header.h"

static void all_NULL(t_app *app);
static void check_file(t_app *app);

char *mx_read_file(char *argv[], t_app *app) {
    int fd = 0;

    all_NULL(app);
    app->file_name = argv[1];
    fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
            close(fd);
            mx_print_all_error(FILE_DOES_NOT_EXIST, app);
        }
    close(fd);
    app->file_to_str = mx_file_to_str(argv[1]);
    if (mx_strlen(app->file_to_str) == 0)
        mx_print_all_error(FILE_IS_EMPTY, app);
    if (app->file_to_str[0] == '\n')
        mx_print_all_error(LINE1_IS_NOT_VALID, app);
    app->pars_lines_arr = mx_strsplit(app->file_to_str, '\n');
        check_file(app); 
    return app->file_to_str;
}


static void check_file(t_app *app) {
    char ** line = NULL;

    line = app->pars_lines_arr;
    if (mx_strlen(line[0]) > 4)
        mx_print_all_error(INVALID_NUMBER_OF_ISLANDS, app);
    app->SIZE = mx_atoi(line[0]);
    if(app->SIZE == 0 && !line[1])
        exit(0);
    if(app->SIZE == 0 && line[1])
        mx_print_all_error(INVALID_NUMBER_OF_ISLANDS, app);
    if(app->SIZE == -1)
        mx_print_all_error(INVALID_NUMBER_OF_ISLANDS, app);
}

static void all_NULL(t_app *app) {
    app->file_to_str = NULL;
    app->city = NULL;
    app->pars_lines_arr = NULL;
    app->A_M = NULL;
    app->D_M = NULL;
}

