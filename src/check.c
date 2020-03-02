#include <stdio.h>
#include <string.h>
#include <unistd.h>

void check_empty_lines(char *str) {
    int k = 0;
    int j = 0;
    if (str[0] == '\n')
        printf("LINE1_IS_NOT_VALID, app");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
        if (str[i] == '\n' && str[i+1] == '\n') {
            k = j + 1;
            printf("error");
            break;
        }
    }
}
int main() {
    char *str = "4\nA-B,3\nB-C,4\n\nA-C,1\nC-D,3";
    check_empty_lines(str);
}