
#include <stdio.h>
#include <string.h>

#define size 100

//decelerations
int substring_checker(char *main_string, char *substring);

//main
int main() {
    char s1[size], s2[size];

    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    if (substring_checker(s1, s2) == 1)
        printf("yes");
    else
        printf("no");

    return 0;
}

//definition
int substring_checker(char *main_string, char *substring) {
    int i = 0;
    int j = 0;
    int temp = 0;
    int flag = 0;

    for (j = 0; j < strlen(main_string); j++) {
        i = 0;
        temp = j;
        flag = 0;
        while (i < strlen(substring) - 1) {
            if (main_string[temp] != substring[i]) {
                flag = 1;
                break;
            } else {
                ++i;
                ++temp;
            }
        }
        if (flag == 0)
            return 1;
    }
    return 0;
}
