#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26  // Only lowercase a-z

// Trie node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Create a new trie node
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a key into trie
void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* pCrawl = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a'; // Map 'a'-'z' to 0-25
        if (!pCrawl->children[index])
            pCrawl->children[index] = createNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    printf("Inserted key: %s\n", key);
}

// Search for a key in trie
bool search(struct TrieNode* root, const char* key) {
    struct TrieNode* pCrawl = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Main function
int main() {
    struct TrieNode* root = createNode();

    int n;
    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    char key[100];
    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%s", key);
        insert(root, key);
    }

    int q;
    printf("Enter number of keys to search: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        printf("Enter key to search: ");
        scanf("%s", key);
        if (search(root, key))
            printf("Key '%s' found in trie.\n", key);
        else
            printf("Key '%s' not found in trie.\n", key);
    }

    return 0;
}

