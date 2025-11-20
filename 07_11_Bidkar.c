#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i = 0;
    char ch;
    int op1, op2, value;

    while ((ch = exp[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');  // convert char to int
        } else {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression (single-digit operands, e.g., 23*5+): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}

