#include "header.h"

static void check_empty_lines(t_app *app);

void mx_init(int argc, char *argv[], t_app *app) {
    if(argc != 2) {
        mx_print_all_error(INVALID_NUM_COMAND_LINE_ARG, app);
    }
    mx_read_file(argv, app);
    mx_parse_all_lines(app, app->pars_lines_arr);
    if (app->city[app->SIZE - 1] == NULL) {
        mx_print_all_error(INVALID_NUMBER_OF_ISLANDS, app);
    }
    check_empty_lines(app);
}

static void check_empty_lines(t_app *app) {
    char *str = NULL;
    int j = 0;

    str = app->file_to_str;
    if (str[0] == '\n')
        mx_print_all_error(LINE1_IS_NOT_VALID, app);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
        if (str[i] == '\n' && str[i+1] == '\n') {
            app->k = j + 1;
            mx_print_all_error(LINE_IS_EMPTY, app);

        }
    }
}

