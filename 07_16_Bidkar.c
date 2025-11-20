
#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find minimum value in BST
int findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->data;
}

// Function to find maximum value in BST
int findMax(struct Node* root) {
    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->data;
}

// Main function
int main() {
    struct Node* root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 12);
    insert(root, 17);
    insert(root, 25);

    printf("Minimum value in BST: %d\n", findMin(root));
    printf("Maximum value in BST: %d\n", findMax(root));

    return 0;
}
