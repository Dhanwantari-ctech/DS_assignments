#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insertBST(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// BFS / Level order traversal
void BFS(struct Node* root) {
    if (!root) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

// DFS (similar to Preorder)
void DFS(struct Node* root) {
    preorder(root);
}

// Mirror BST
void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

// Find node
struct Node* findNode(struct Node* root, int value) {
    if (!root) return NULL;
    if (root->data == value) return root;
    if (value < root->data) return findNode(root->left, value);
    else return findNode(root->right, value);
}

// Find parent of a node
struct Node* findParent(struct Node* root, struct Node* child) {
    if (!root || root == child) return NULL;
    if (root->left == child || root->right == child) return root;
    if (child->data < root->data)
        return findParent(root->left, child);
    else
        return findParent(root->right, child);
}

// Children of a node
void printChildren(struct Node* root, int value) {
    struct Node* node = findNode(root, value);
    if (!node) {
        printf("Node not found.\n");
        return;
    }
    printf("Children of %d: ", value);
    if (node->left) printf("%d ", node->left->data);
    if (node->right) printf("%d ", node->right->data);
    if (!node->left && !node->right) printf("No children");
    printf("\n");
}

// Sibling of a node
void printSibling(struct Node* root, int value) {
    struct Node* parent = findParent(root, findNode(root, value));
    if (!parent) {
        printf("Sibling not found (root node or node missing).\n");
        return;
    }
    if (parent->left && parent->left->data != value)
        printf("Sibling: %d\n", parent->left->data);
    else if (parent->right && parent->right->data != value)
        printf("Sibling: %d\n", parent->right->data);
    else
        printf("No sibling\n");
}

// Grandparent of a node
void printGrandparent(struct Node* root, int value) {
    struct Node* parent = findParent(root, findNode(root, value));
    if (!parent) {
        printf("Grandparent not found (parent missing).\n");
        return;
    }
    struct Node* grandparent = findParent(root, parent);
    if (grandparent)
        printf("Grandparent: %d\n", grandparent->data);
    else
        printf("No grandparent\n");
}

// Uncle of a node
void printUncle(struct Node* root, int value) {
    struct Node* parent = findParent(root, findNode(root, value));
    if (!parent) {
        printf("Uncle not found (parent missing).\n");
        return;
    }
    struct Node* grandparent = findParent(root, parent);
    if (!grandparent) {
        printf("No uncle (grandparent missing).\n");
        return;
    }
    if (grandparent->left == parent && grandparent->right)
        printf("Uncle: %d\n", grandparent->right->data);
    else if (grandparent->right == parent && grandparent->left)
        printf("Uncle: %d\n", grandparent->left->data);
    else
        printf("No uncle\n");
}

// Main menu
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n");
        printf("5. BFS (Level Order)\n6. DFS\n7. Mirror Tree\n8. Children\n");
        printf("9. Sibling\n10. Parent\n11. Grandparent\n12. Uncle\n13. Exit\n");
        printf("Enter choice: "); scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: "); scanf("%d", &value);
                root = insertBST(root, value);
                break;
            case 2:
                inorder(root); printf("\n"); break;
            case 3:
                preorder(root); printf("\n"); break;
            case 4:
                postorder(root); printf("\n"); break;
            case 5:
                BFS(root); printf("\n"); break;
            case 6:
                DFS(root); printf("\n"); break;
            case 7:
                mirror(root); printf("Tree mirrored.\n"); break;
            case 8:
                printf("Enter node value: "); scanf("%d", &value);
                printChildren(root, value);
                break;
            case 9:
                printf("Enter node value: "); scanf("%d", &value);
                printSibling(root, value);
                break;
            case 10:
                printf("Enter node value: "); scanf("%d", &value);
                {
                    struct Node* parent = findParent(root, findNode(root, value));
                    if (parent) printf("Parent: %d\n", parent->data);
                    else printf("No parent (root node)\n");
                }
                break;
            case 11:
                printf("Enter node value: "); scanf("%d", &value);
                printGrandparent(root, value);
                break;
            case 12:
                printf("Enter node value: "); scanf("%d", &value);
                printUncle(root, value);
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

