#include <stdio.h>
#include <stdlib.h>

void solve(int n, int *a) {
    // Kadane's algorithm for contiguous maximum
    int best = a[0], current = a[0];
    for (int i = 1; i < n; i++) {
        current = (current + a[i] > a[i]) ? current + a[i] : a[i];
        if (current > best) best = current;
    }

    // Non-contiguous maximum
    int subseq = 0, hasPositive = 0, largest = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            subseq += a[i];
            hasPositive = 1;
        }
        if (a[i] > largest) largest = a[i];
    }
    if (!hasPositive) subseq = largest;

    printf("%d %d\n", best, subseq);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        solve(n, arr);
        free(arr);
    }
    return 0;
}
