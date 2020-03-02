#include "header.h"

int mx_atoi(char *s) {
    unsigned int res = 0;

    while (*s != '\0') {
            if (!mx_isdigit(*s))
                return -1;
            res = ((10 * res) + (*s) - '0');
            s++;
            
    }
    return (int)res;
   
}

