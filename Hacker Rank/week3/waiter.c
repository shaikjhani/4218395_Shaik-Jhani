#include <stdio.h>
#include <math.h>

#define N 1300
#define M 110000

int ans[M], stk[M], tmpstk[M], prim[N];
int atop = 0, top = 0, ttop = 0, n, q, num;

void init() {
    num = 0;
    for (int i = 2; i < M; ++i) {
        int isPrime = 1;
        for (int j = 2; j <= (int)sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            prim[num++] = i;
        }
        if (num >= 1200)
            return;
    }
}

int main() {
    scanf("%d %d", &n, &q);
    init();

    atop = top = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &stk[top++]);
    }

    for (int i = 0; i < q; ++i) {
        ttop = 0;

        while (top) {
            int v = stk[--top];
            if (v % prim[i] == 0) {
                ans[atop++] = v;
            } else {
                tmpstk[ttop++] = v;
            }
        }

        while (atop) {
            printf("%d\n", ans[--atop]);
        }

        for (int j = 0; j < ttop; ++j) {
            stk[j] = tmpstk[j];
        }
        top = ttop;

        if (!top) break;
    }

    while (top) {
        printf("%d\n", stk[--top]);
    }

    return 0;
}
