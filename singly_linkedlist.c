#include <stdio.h>
#include <stdlib.h>

struct node {
    int bill;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice, amount, total, max, min;

    do {
        printf("\n--- Coffee Shop Menu ---\n");
        printf("1. Add Bill\n");
        printf("2. Display Total Sale\n");
        printf("3. Display Maximum Bill\n");
        printf("4. Display Minimum Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add bill
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter bill amount: ");
                scanf("%d", &amount);
                newnode->bill = amount;
                newnode->next = NULL;

                if (head == NULL) {
                    head = newnode;
                } else {
                    temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newnode;
                }
                printf("Bill added successfully.\n");
                break;

            case 2: // Total sale
                total = 0;
                temp = head;
                if (temp == NULL) {
                    printf("No bills recorded.\n");
                } else {
                    while (temp != NULL) {
                        total = total + temp->bill;
                        temp = temp->next;
                    }
                    printf("Total Sale of the Day: %d\n", total);
                }
                break;

            case 3: // Maximum bill
                if (head == NULL) {
                    printf("No bills recorded.\n");
                } else {
                    temp = head;
                    max = temp->bill;
                    while (temp != NULL) {
                        if (temp->bill > max) {
                            max = temp->bill;
                        }
                        temp = temp->next;
                    }
                    printf("Maximum Bill of the Day: %d\n", max);
                }
                break;

            case 4: // Minimum bill
                if (head == NULL) {
                    printf("No bills recorded.\n");
                } else {
                    temp = head;
                    min = temp->bill;
                    while (temp != NULL) {
                        if (temp->bill < min) {
                            min = temp->bill;
                        }
                        temp = temp->next;
                    }
                    printf("Minimum Bill of the Day: %d\n", min);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}

