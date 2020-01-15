#include "header.h"

static _Bool parseline(char *line, char **isl_1, char **isl_2, int *dist);
static _Bool is_valid(char *s);
static void free_isl(char *isl_1, char *isl_2);
static void check_sum(t_app *app, int dist);

void mx_parse_all_lines(t_app *app, char **str) {
    mx_city_init(app);
    for (int i = 1; str[i] != NULL; i++) {
        char *isl_1 = NULL;
        char *isl_2 = NULL;
        int dist = -1;

        if (parseline(str[i], &isl_1, &isl_2, &dist)) {
            check_sum(app, dist);
            mx_city_push(isl_1, isl_2, app);
            mx_matrix_index(app, isl_1, isl_2, dist);
        }
        else {
            free_isl(isl_1, isl_2);
            app->invalid_line_num = i + 1;
            mx_print_all_error(LINE_IS_NOT_VALID, app);
        }
        free_isl(isl_1, isl_2);
    }
}

static _Bool parseline(char *line, char **isl_1, char **isl_2, int *dist) {
    int index_dash = mx_get_char_index(line, '-');
    int index_comma = mx_get_char_index(line, ',');
    char *ascii_digit = NULL;
    int len = mx_strlen(line);

    if (index_dash == -1 || index_comma == -1 || len == 0 ||
       index_dash > index_comma)
        return false;
    *isl_1 = mx_strndup(line, index_dash);
    *isl_2 = mx_strndup(line + index_dash + 1, index_comma - index_dash - 1);
    if (!is_valid(*isl_1) || !is_valid(*isl_2))
        return false;
    ascii_digit = mx_strndup(line + index_comma + 1, len - index_comma - 1);
    *dist = mx_atoi(ascii_digit);
    if (*dist == 0 || *dist == -1 || *dist == -2)
        return false;
    free(ascii_digit);
    return true;
}

static _Bool is_valid(char *s) {
    if (mx_strlen(s) == 0)
        return false;
    for (int i = 0; s[i] != '\0'; i++) {
        if(!mx_isalpha(s[i]))
            return false;
    }
    return true;
}

static void free_isl(char *isl_1, char *isl_2) {
    free(isl_1);
    free(isl_2);
}

static void check_sum(t_app *app, int dist) {
    if(app->sum_dist < 2147483647) {
        app->sum_dist += dist;
    }
    else 
        exit(1);
}

