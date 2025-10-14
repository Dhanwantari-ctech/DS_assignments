#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Underflow
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to check matching brackets
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if expression is balanced
int areParenthesesBalanced(const char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                return 0; // No matching opening
            }
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, ch)) {
                return 0; // Mismatched pair
            }
        }
    }

    return isEmpty(&s); // If stack is empty, it's balanced
}

// Main function
int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression has unbalanced parentheses.\n");
    }

    return 0;
}
