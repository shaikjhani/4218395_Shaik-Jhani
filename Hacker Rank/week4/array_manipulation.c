#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    // Allocate with N+2 to safely handle range updates
    long long *diff = (long long*)calloc(N + 2, sizeof(long long));

    // Process all queries
    for (int i = 0; i < Q; i++) {
        int L, R;
        long long val;
        scanf("%d %d %lld", &L, &R, &val);

        diff[L] += val;
        diff[R + 1] -= val;
    }

    // Compute prefix sum and find maximum
    long long current = 0, maximum = LLONG_MIN;
    for (int i = 1; i <= N; i++) {
        current += diff[i];
        if (current > maximum) {
            maximum = current;
        }
    }

    printf("%lld\n", maximum);

    free(diff);
    return 0;
}
