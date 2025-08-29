#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LETTERS 26

// Trie node structure
typedef struct Node {
    bool endOfWord;
    struct Node* next[LETTERS];
} Node;

// Create a fresh node
Node* createNode() {
    Node* t = (Node*)malloc(sizeof(Node));
    t->endOfWord = false;
    for (int i = 0; i < LETTERS; i++) {
        t->next[i] = NULL;
    }
    return t;
}

// Try inserting a string, return false if prefix violation
bool addWord(Node* root, const char* s) {
    Node* crawler = root;
    for (int i = 0; s[i]; i++) {
        int k = s[i] - 'a';
        if (crawler->next[k] == NULL) {
            crawler->next[k] = createNode();
        }
        crawler = crawler->next[k];

        // Existing word is prefix of new word
        if (crawler->endOfWord) return false;
    }

    // New word itself cannot be prefix of others
    for (int j = 0; j < LETTERS; j++) {
        if (crawler->next[j] != NULL) return false;
    }

    crawler->endOfWord = true;
    return true;
}

int main() {
    int count;
    scanf("%d", &count);

    Node* root = createNode();
    char buffer[64];

    for (int i = 0; i < count; i++) {
        scanf("%s", buffer);
        if (!addWord(root, buffer)) {
            printf("BAD SET\n%s\n", buffer);
            return 0;
        }
    }

    printf("GOOD SET\n");
    return 0;
}
