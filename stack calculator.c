#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression (e.g., 23*5+): ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}

