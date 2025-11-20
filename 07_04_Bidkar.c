#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX,  rear2 = MAX;

void enqueue1() {
    int x;
    if (rear1 + 1 == rear2) {
        printf("\nQueue 1 Overflow! No space.\n");
        return;
    }
    printf("Enter value to enqueue in Queue 1: ");
    scanf("%d", &x);

    if (front1 == -1) front1 = 0;
    arr[++rear1] = x;

    printf("%d inserted into Queue 1.\n", x);
}

void enqueue2() {
    int x;
    if (rear1 + 1 == rear2) {
        printf("\nQueue 2 Overflow! No space.\n");
        return;
    }
    printf("Enter value to enqueue in Queue 2: ");
    scanf("%d", &x);

    if (front2 == MAX) front2 = MAX - 1;
    arr[--rear2] = x;

    printf("%d inserted into Queue 2.\n", x);
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("\nQueue 1 Underflow!\n");
        return;
    }
    printf("%d removed from Queue 1.\n", arr[front1++]);

    if (front1 > rear1) front1 = rear1 = -1;
}

void dequeue2() {
    if (front2 == MAX || front2 < rear2) {
        printf("\nQueue 2 Underflow!\n");
        return;
    }
    printf("%d removed from Queue 2.\n", arr[front2--]);

    if (front2 < rear2) front2 = rear2 = MAX;
}

void display1() {
    if (front1 == -1) {
        printf("\nQueue 1 is empty.\n");
        return;
    }
    printf("\nQueue 1 elements: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2() {
    if (front2 == MAX) {
        printf("\nQueue 2 is empty.\n");
        return;
    }
    printf("\nQueue 2 elements: ");
    for (int i = front2; i >= rear2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("     TWO QUEUES USING ONE ARRAY      \n");
        printf("=====================================\n");
        printf("1. Enqueue in Queue 1\n");
        printf("2. Dequeue from Queue 1\n");
        printf("3. Display Queue 1\n");
        printf("4. Enqueue in Queue 2\n");
        printf("5. Dequeue from Queue 2\n");
        printf("6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue1(); break;
            case 2: dequeue1(); break;
            case 3: display1(); break;
            case 4: enqueue2(); break;
            case 5: dequeue2(); break;
            case 6: display2(); break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

