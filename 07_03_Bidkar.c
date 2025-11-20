#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1() {
    int x;
    if (top1 + 1 == top2) {
        printf("\nOverflow! No space in array.\n");
        return;
    }
    printf("Enter value to push in Stack 1: ");
    scanf("%d", &x);
    arr[++top1] = x;
    printf("%d pushed into Stack 1.\n", x);
}

void push2() {
    int x;
    if (top1 + 1 == top2) {
        printf("\nOverflow! No space in array.\n");
        return;
    }
    printf("Enter value to push in Stack 2: ");
    scanf("%d", &x);
    arr[--top2] = x;
    printf("%d pushed into Stack 2.\n", x);
}

void pop1() {
    if (top1 == -1) {
        printf("\nStack 1 Underflow!\n");
        return;
    }
    printf("%d popped from Stack 1.\n", arr[top1--]);
}

void pop2() {
    if (top2 == MAX) {
        printf("\nStack 2 Underflow!\n");
        return;
    }
    printf("%d popped from Stack 2.\n", arr[top2++]);
}

void display1() {
    if (top1 == -1) {
        printf("\nStack 1 is empty.\n");
        return;
    }
    printf("\nStack 1 elements: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2() {
    if (top2 == MAX) {
        printf("\nStack 2 is empty.\n");
        return;
    }
    printf("\nStack 2 elements: ");
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n==================================\n");
        printf("     TWO STACKS (ONE ARRAY)       \n");
        printf("==================================\n");
        printf("1. Push in Stack 1\n");
        printf("2. Pop from Stack 1\n");
        printf("3. Display Stack 1\n");
        printf("4. Push in Stack 2\n");
        printf("5. Pop from Stack 2\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("==================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push1(); break;
            case 2: pop1(); break;
            case 3: display1(); break;
            case 4: push2(); break;
            case 5: pop2(); break;
            case 6: display2(); break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

