#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';   // indicates underflow
    }
    return stack[top--];
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkBalanced(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket, check match
        else if (ch == ')' || ch == '}' || ch == ']') {
            char popped = pop();

            if (!isMatchingPair(popped, ch)) {
                return false;  // mismatch found
            }
        }
    }

    // If stack is empty → balanced
    return (top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checkBalanced(expr))
        printf("Parentheses are BALANCED.\n");
    else
        printf("Parentheses are NOT BALANCED.\n");

    return 0;
}

