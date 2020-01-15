#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"

typedef enum e_ERR {
    INVALID_NUM_COMAND_LINE_ARG,
    FILE_DOES_NOT_EXIST,
    FILE_IS_EMPTY,
    LINE1_IS_NOT_VALID,
    LINE_IS_NOT_VALID,
    INVALID_NUMBER_OF_ISLANDS,
    LINE_IS_EMPTY
} e_error;

typedef struct s_APP {
    int SIZE;
    char *file_name;
    char *file_to_str;
    char ** city;
    char **pars_lines_arr;
    int *A_M;
    int *D_M;
    int invalid_line_num;
    int k;
    unsigned int sum_dist;
} t_app;

typedef struct s_Stack {
    int *path;
    int size;
    int max_size;
} t_stack;

int mx_atoi(char *s);
_Bool mx_isdigit(int c);
_Bool mx_isalpha(int c);
char *mx_read_file(char *argv[], t_app *app);
void mx_print_err(const char *s);
void mx_print_all_error (e_error errors, t_app *app);
void mx_init(int argc, char *argv[], t_app *app);
void mx_parse_all_lines(t_app *app, char **str);
void mx_city_init(t_app *app);
void mx_make_Floyd_matrix(t_app *app);
void mx_city_push(char *isl_1, char * isl_2, t_app *app);
void mx_matrix_index(t_app *app, char * isl_1, char * isl_2, int dist);
void mx_push_in_AM(t_app *app, int dist, int i, int j);
void mx_free_all(t_app *app);
void mx_restore_all_path(t_app *app);
int mx_pop_from_stack(t_stack *st);
void mx_push_in_stack(t_stack *st, int element);
int mx_top_from_stack(t_stack *st);
void mx_print_path(t_app *app, t_stack *st);
void mx_print_line(void);
void mx_matrix_index(t_app *app, char * isl_1, char * isl_2, int dist);
#endif

