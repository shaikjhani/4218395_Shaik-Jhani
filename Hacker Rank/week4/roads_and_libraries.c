#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100010

int seen[LIMIT];
int *graph[LIMIT];
int gSize[LIMIT];

void explore(int node, int *cnt) {
    seen[node] = 1;
    (*cnt)++;
    for (int i = 0; i < gSize[node]; i++) {
        int nxt = graph[node][i];
        if (!seen[nxt]) {
            explore(nxt, cnt);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        long costLib, costRoad;
        scanf("%d %d %ld %ld", &n, &m, &costLib, &costRoad);

        // initialize
        for (int i = 1; i <= n; i++) {
            gSize[i] = 0;
            seen[i] = 0;
            free(graph[i]);
            graph[i] = NULL;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a] = realloc(graph[a], (gSize[a] + 1) * sizeof(int));
            graph[b] = realloc(graph[b], (gSize[b] + 1) * sizeof(int));
            graph[a][gSize[a]++] = b;
            graph[b][gSize[b]++] = a;
        }

        if (costRoad >= costLib) {
            // build library everywhere
            printf("%ld\n", costLib * n);
        } else {
            long result = 0;
            for (int i = 1; i <= n; i++) {
                if (!seen[i]) {
                    int nodes = 0;
                    explore(i, &nodes);
                    result += costLib + (nodes - 1) * costRoad;
                }
            }
            printf("%ld\n", result);
        }
    }
    return 0;
}
