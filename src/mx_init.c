#include "header.h"

void mx_init(int argc, char *argv[], t_app *app) {
    if(argc != 2) {
        mx_print_all_error(INVALID_NUM_COMAND_LINE_ARG, app);
    }
    mx_read_file(argv, app);
    mx_parse_all_lines(app, app->pars_lines_arr);
    if (app->city[app->SIZE - 1] == NULL) {
        mx_print_all_error(LINE1_IS_NOT_VALID, app);
    }
}
