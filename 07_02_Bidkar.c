#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int x;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert.\n");
    } else {
        printf("Enter value to enqueue: ");
        scanf("%d", &x);

        if (front == -1)  // first insertion
            front = 0;

        queue[++rear] = x;
        printf("%d inserted into queue.\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Nothing to delete.\n");
    } else {
        printf("%d deleted from queue.\n", queue[front++]);

        // Reset when queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n========================\n");
        printf("       QUEUE MENU       \n");
        printf("========================\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

