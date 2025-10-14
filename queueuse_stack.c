#include <stdio.h>
#define MAX 5

int main() {
    int S1[MAX], S2[MAX];
    int top1 = -1, top2 = -1;
    int choice, val, i;

    do {
        printf("\n--- Queue using Stack Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                if (top1 == MAX - 1) {
                    printf("Queue is FULL\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &val);
                    S1[++top1] = val;
                    printf("%d inserted into queue\n", val);
                }
                break;

            case 2: // Dequeue
                if (top1 == -1 && top2 == -1) {
                    printf("Queue is EMPTY\n");
                } else {
                    if (top2 == -1) { // move S1 -> S2
                        while (top1 != -1) {
                            S2[++top2] = S1[top1--];
                        }
                    }
                    printf("%d deleted from queue\n", S2[top2--]);
                }
                break;

            case 3: // Display
                if (top1 == -1 && top2 == -1) {
                    printf("Queue is EMPTY\n");
                } else {
                    printf("Queue elements (Front to Rear): ");
                    // First print elements in S2 (top to bottom = front to middle)
                    for (i = top2; i >= 0; i--) {
                        printf("%d ", S2[i]);
                    }
                    // Then print elements in S1 (bottom to top = middle to rear)
                    for (i = 0; i <= top1; i++) {
                        printf("%d ", S1[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

