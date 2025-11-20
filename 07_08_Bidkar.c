
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to reverse a string
void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    char ch, x;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);  // Step 1

    // Step 2: Swap '(' and ')'
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    top = -1;  // Reset stack
    i = 0;
    k = 0;

    // Step 3: Convert to postfix (normal infix→postfix)
    while ((ch = infix[i++]) != '\0') {

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    // Step 4: Reverse postfix → prefix
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
