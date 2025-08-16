#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *data = malloc(n * sizeof(int));
    if (!data) return 1;

    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        if (data[i] > max) max = data[i];
    }

    int limit = (max < 99) ? 100 : (max + 1);
    int *freq = calloc(limit, sizeof(int));
    if (!freq) { free(data); return 1; }

    for (int i = 0; i < n; i++) if (data[i] >= 0) freq[data[i]]++;

    for (int i = 0; i < 100; i++) {
        if (i) printf(" ");
        printf("%d", freq[i]);
    }
    printf("\n");

    free(data);
    free(freq);
    return 0;
}
