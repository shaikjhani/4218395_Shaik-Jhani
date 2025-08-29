#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 256   // maximum ASCII characters

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    Node* arr[LIMIT];
    int size;
} PriorityQueue;

Node* createNode(char ch, int freq) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

void swap(Node** x, Node** y) {
    Node* tmp = *x;
    *x = *y;
    *y = tmp;
}

void heapifyDown(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < pq->size && pq->arr[l]->freq < pq->arr[smallest]->freq) smallest = l;
    if (r < pq->size && pq->arr[r]->freq < pq->arr[smallest]->freq) smallest = r;

    if (smallest != idx) {
        swap(&pq->arr[smallest], &pq->arr[idx]);
        heapifyDown(pq, smallest);
    }
}

Node* extractMin(PriorityQueue* pq) {
    Node* res = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return res;
}

void insertHeap(PriorityQueue* pq, Node* n) {
    int i = pq->size;
    pq->arr[i] = n;
    pq->size++;

    while (i > 0 && pq->arr[i]->freq < pq->arr[(i - 1) / 2]->freq) {
        swap(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node* buildHuffmanTree(char symbols[], int freq[], int count) {
    PriorityQueue pq = { .size = 0 };

    for (int i = 0; i < count; i++)
        insertHeap(&pq, createNode(symbols[i], freq[i]));

    while (pq.size > 1) {
        Node* left = extractMin(&pq);
        Node* right = extractMin(&pq);

        Node* parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        insertHeap(&pq, parent);
    }

    return extractMin(&pq);
}

void generateCodes(Node* root, char buffer[], int depth, char codeTable[LIMIT][LIMIT]) {
    if (root->left) {
        buffer[depth] = '0';
        generateCodes(root->left, buffer, depth + 1, codeTable);
    }
    if (root->right) {
        buffer[depth] = '1';
        generateCodes(root->right, buffer, depth + 1, codeTable);
    }
    if (!root->left && !root->right) {
        buffer[depth] = '\0';
        strcpy(codeTable[(unsigned char)root->ch], buffer);
    }
}

void decodeText(Node* root, const char* bits) {
    Node* cur = root;
    for (int i = 0; bits[i]; i++) {
        cur = (bits[i] == '0') ? cur->left : cur->right;

        if (!cur->left && !cur->right) {
            printf("%c", cur->ch);
            cur = root;
        }
    }
    printf("\n");
}

int main() {
    char input[1000];
    scanf("%s", input);

    int freq[LIMIT] = {0};
    for (int i = 0; input[i]; i++) {
        freq[(unsigned char)input[i]]++;
    }

    char symbols[LIMIT];
    int counts[LIMIT];
    int unique = 0;

    for (int i = 0; i < LIMIT; i++) {
        if (freq[i] > 0) {
            symbols[unique] = (char)i;
            counts[unique] = freq[i];
            unique++;
        }
    }

    Node* root = buildHuffmanTree(symbols, counts, unique);

    char codes[LIMIT][LIMIT] = {0};
    char temp[LIMIT];
    generateCodes(root, temp, 0, codes);

    char encoded[5000] = "";
    for (int i = 0; input[i]; i++) {
        strcat(encoded, codes[(unsigned char)input[i]]);
    }

    decodeText(root, encoded);

    return 0;
}

