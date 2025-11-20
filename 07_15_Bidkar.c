#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Print BST values in range [low, high]
void printInRange(struct Node* root, int low, int high) {
    if (root == NULL) return;

    // Only traverse left subtree if there could be values >= low
    if (root->data > low)
        printInRange(root->left, low, high);

    // Print current node if it's in range
    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    // Only traverse right subtree if there could be values <= high
    if (root->data < high)
        printInRange(root->right, low, high);
}

int main() {
    struct Node* root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    int low = 30, high = 65;
    printf("BST values in range [%d, %d]:\n", low, high);
    printInRange(root, low, high);
    printf("\n");

    return 0;
}

