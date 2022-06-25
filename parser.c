#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **parse(char *func);
int isOneChar(char ch);
int isFunction(char ch);

int main() {
    char *testString = "x*sin(x)\0";
    char **tokens = parse(testString);
    int i = 0;
    while(*tokens[i] != '\0') {
        printf("%s\n", tokens[i]);
        i++;
    }
    return 0;
}

// 3+4*sin(1/x^123)

char **parse(char *func) {
    int i = 0, token = 0;
    int len = strlen(func);
    char **tokens = malloc(len * sizeof(char*));
    while (func[i] != '\0') {
        // printf("%c\n", func[i]);
        if (isOneChar(func[i]) == 1) {
            // printf("Inside isOneChar\n");
            // tokens[token] = &func[i];
            char *str = malloc(sizeof(char) * 1);
            str[0] = func[i];
            tokens[token] = str;
            // printf("%s\n", tokens[token]);
            token++;
            // printf("%c\n", func[i]);
        }
        
        // if (is_number(func[i]) == 1) {
        //     if(is_number(func[i-1]))
        // }
        if (isFunction(func[i]) == 1) {
            // printf("Inside isFunction\n");
            char *str = malloc(sizeof(char) * 6);
            str[0] = '\0';
            str[1] = '\0';
            str[2] = '\0';
            str[3] = '\0';
            str[4] = '\0';
            str[5] = '\0';
            // char str[] = {'\0', '\0', '\0', '\0', '\0', '\0'};
            while(func [i] != '(') {
                char temp = func[i];
                strcat(str, &temp); //s i n (
                i++;
            }
            strcat(str, "(");
            tokens[token] = str;
            // printf("%s\n", tokens[token]);
            token++;
            // printf("After assigning\n");
        }
        i++;

    }
    // printf("Before return");
    return tokens;
}

int isOneChar(char ch) {
    int ret = 0;
    if (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == ')'
    || ch == 'x') {
        ret = 1;
    }
    return ret;
}

// int is_number (char *ch) {
//     int ret = 0;
//     if (ch >= 48 && ch <= 57) {
//         ret = 1;
//     }
//     return ret;
// }

int isFunction(char ch) {
    int ret = 0;
    if (ch >= 97 && ch <= 122 && ch != 'x') {
        ret = 1;
    }
    return ret;
}
