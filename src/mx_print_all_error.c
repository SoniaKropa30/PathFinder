#include "header.h"

static void er_FILE_DOES_NOT_EXIST(t_app *app);
static void er_FILE_IS_EMPTY(t_app *app);
static void er_LINE_IS_NOT_VALID(t_app *app);
static void er_LINE_IS_EMPTY(t_app *app);

void mx_print_all_error(e_error errors, t_app *app) {
        if (errors == INVALID_NUM_COMAND_LINE_ARG)
            mx_print_err("usage: ./pathfinder [filename]");
        else if (errors == FILE_DOES_NOT_EXIST)
            er_FILE_DOES_NOT_EXIST(app);
        else if (errors == FILE_IS_EMPTY)
            er_FILE_IS_EMPTY(app);
        else if (errors == LINE1_IS_NOT_VALID)
            mx_print_err("error: line 1 is not valid");
        else if (errors == LINE_IS_NOT_VALID)
            er_LINE_IS_NOT_VALID(app);
        else if (errors == INVALID_NUMBER_OF_ISLANDS)
            mx_print_err("error: invalid number of islands");
        else if (errors == LINE_IS_EMPTY)
            er_LINE_IS_EMPTY(app);
    mx_print_err("\n");
    exit(1);
}

static void  er_FILE_DOES_NOT_EXIST(t_app *app) {
    mx_print_err("error: file ");
    mx_print_err(app->file_name);
    mx_print_err(" does not exist");
}

static void er_FILE_IS_EMPTY(t_app *app) {
    mx_print_err("error: file ");
    mx_print_err(app->file_name);
    mx_print_err(" is empty");
}

static void er_LINE_IS_NOT_VALID(t_app *app) {
    char *line_num = NULL;
    
    line_num = mx_itoa(app->invalid_line_num);
    mx_print_err("error: line ");
    mx_print_err(line_num);
    free(line_num);
    line_num = NULL;
    mx_print_err(" is not valid");
}

static void er_LINE_IS_EMPTY(t_app *app) {
    char *line_num = NULL;

    line_num = mx_itoa(app->k);
    mx_print_err("error: line ");
    mx_print_err(line_num);
    free(line_num);
    line_num = NULL;
    mx_print_err(" is not valid");
}

