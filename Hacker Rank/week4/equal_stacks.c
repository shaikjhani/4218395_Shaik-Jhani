#include <stdio.h>
#include <stdlib.h>

int sum(int n, int *a) {
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}

int equalStacks(int n1, int *s1, int n2, int *s2, int n3, int *s3) {
    int h1 = sum(n1, s1), h2 = sum(n2, s2), h3 = sum(n3, s3);
    int i1 = 0, i2 = 0, i3 = 0;

    while (1) {
        if (i1 == n1 || i2 == n2 || i3 == n3) return 0;
        if (h1 == h2 && h2 == h3) return h1;

        if (h1 >= h2 && h1 >= h3) h1 -= s1[i1++];
        else if (h2 >= h1 && h2 >= h3) h2 -= s2[i2++];
        else h3 -= s3[i3++];
    }
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int *s1 = malloc(n1 * sizeof(int));
    int *s2 = malloc(n2 * sizeof(int));
    int *s3 = malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) scanf("%d", &s1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &s2[i]);
    for (int i = 0; i < n3; i++) scanf("%d", &s3[i]);

    printf("%d\n", equalStacks(n1, s1, n2, s2, n3, s3));

    free(s1); free(s2); free(s3);
    return 0;
}
