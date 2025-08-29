#include <stdio.h>
#include <stdlib.h>

// Structure to store number and its original position
typedef struct {
    int num;
    int pos;
} Node;

// Comparator for ascending order
int compareAsc(const void* a, const void* b) {
    return ((Node*)a)->num - ((Node*)b)->num;
}

// Count swaps required to reorder into given order
int findSwaps(int* arr, int n, int ascending) {
    Node* nodes = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].num = arr[i];
        nodes[i].pos = i;
    }

    // Sort array copy
    qsort(nodes, n, sizeof(Node), compareAsc);

    // If descending is needed, reverse the sorted order
    if (!ascending) {
        for (int i = 0; i < n / 2; i++) {
            Node tmp = nodes[i];
            nodes[i] = nodes[n - 1 - i];
            nodes[n - 1 - i] = tmp;
        }
    }

    // Track visited indices
    int* visited = (int*)calloc(n, sizeof(int));
    int swapCount = 0;

    // Cycle detection
    for (int i = 0; i < n; i++) {
        if (visited[i] || nodes[i].pos == i)
            continue;

        int cycleLength = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = nodes[j].pos;
            cycleLength++;
        }
        if (cycleLength > 1)
            swapCount += (cycleLength - 1);
    }

    free(nodes);
    free(visited);
    return swapCount;
}

int lilysHomework(int n, int* arr) {
    int* copy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copy[i] = arr[i];

    int swapsAsc = findSwaps(arr, n, 1);
    int swapsDesc = findSwaps(copy, n, 0);

    free(copy);
    return (swapsAsc < swapsDesc) ? swapsAsc : swapsDesc;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("%d\n", lilysHomework(n, arr));

    free(arr);
    return 0;
}
