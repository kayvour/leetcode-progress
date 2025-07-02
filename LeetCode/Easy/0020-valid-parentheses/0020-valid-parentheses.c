#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char * s) {
    int len = strlen(s);
    char *stack = (char *)malloc(len + 1);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }
            char last = stack[top--];
            if ((current == ')' && last != '(') ||
                (current == '}' && last != '{') ||
                (current == ']' && last != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);
    free(stack);
    return result;
}