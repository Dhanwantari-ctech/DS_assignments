#include <stdio.h>
#include <ctype.h>  // for isalpha(), isdigit()
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char ch, temp;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {

        // If operand → output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If '(' → push
        else if (ch == '(') {
            push(ch);
        }

        // If ')' → pop until '('
        else if (ch == ')') {
            while ((temp = pop()) != '(')
                postfix[j++] = temp;
        }

        // Operator encountered
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

