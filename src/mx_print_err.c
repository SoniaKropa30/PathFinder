#include "header.h"

void mx_print_err(const char *s) {
    write(2, s, mx_strlen(s));
}

