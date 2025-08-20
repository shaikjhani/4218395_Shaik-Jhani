#include <stdio.h>

long solve(long x) {
    if (x == 0) return 1;
    long cnt = 0;
    while (x > 0) {
        if ((x & 1) == 0) cnt++;
        x >>= 1;
    }
    return 1L << cnt;
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", solve(n));
    return 0;
}
