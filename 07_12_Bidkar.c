#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Head of the list
struct Node* head = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at end.\n", value);
}

// Insert after a given value
void insertAfterValue(int value, int after) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != after)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value %d not found in list.\n", after);
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted after %d.\n", value, after);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("%d deleted from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete a node with a given value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("%d deleted.\n", value);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL) {
        printf("%d not found in list.\n", value);
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    printf("%d deleted.\n", value);
}

// Display list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse list
void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}

// Merge two lists
struct Node* mergeLists(struct Node* h1, struct Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct Node* merged;
    if (h1->data < h2->data) {
        merged = h1;
        merged->next = mergeLists(h1->next, h2);
    } else {
        merged = h2;
        merged->next = mergeLists(h1, h2->next);
    }
    return merged;
}

// Find middle node
void findMiddle() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

// Sort list using bubble sort
void sortList() {
    if (head == NULL) return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}

// Detect and remove loop (Floyd’s cycle detection)
void detectAndRemoveLoop() {
    struct Node *slow = head, *fast = head;
    int loopFound = 0;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopFound = 1;
            break;
        }
    }

    if (!loopFound) {
        printf("No loop detected.\n");
        return;
    }

    slow = head;
    struct Node* prev = NULL;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;  // Remove loop
    printf("Loop detected and removed.\n");
}

// Sum of all node data
void sumOfData() {
    int sum = 0;
    struct Node* temp = head;
    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of all node data: %d\n", sum);
}

// Print even data
void printEven() {
    struct Node* temp = head;
    printf("Even elements: ");
    while (temp) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Print odd data
void printOdd() {
    struct Node* temp = head;
    printf("Odd elements: ");
    while (temp) {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value, after;
    struct Node* head2 = NULL;  // For merging example

    while (1) {
        printf("\n========== SINGLY LINKED LIST MENU ==========\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert after value\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete by value\n");
        printf("7. Display list\n8. Reverse list\n9. Find middle\n");
        printf("10. Sort list\n11. Sum of all nodes\n12. Print even nodes\n13. Print odd nodes\n");
        printf("14. Detect and remove loop\n15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("After which value? ");
                scanf("%d", &after);
                insertAfterValue(value, after);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 7:
                displayList();
                break;
            case 8:
                reverseList();
                break;
            case 9:
                findMiddle();
                break;
            case 10:
                sortList();
                break;
            case 11:
                sumOfData();
                break;
            case 12:
                printEven();
                break;
            case 13:
                printOdd();
                break;
            case 14:
                detectAndRemoveLoop();
                break;
            case 15:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

