#include <stdio.h>
#define MOD 1000000007LL
#define MAXM 1000   // adjust according to problem limits

long long J[MAXM+1], H[MAXM+1], A[MAXM+1]; 

long long N(long long base, int exp) { 
    long long ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ans;
}

int main() {
    int T; 
    scanf("%d", &T);

    int nList[T], mList[T], maxM = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &nList[i], &mList[i]);
        if (mList[i] > maxM) maxM = mList[i];
    }

    // ways to build a row of width w
    J[0] = 1;
    for (int w = 1; w <= maxM; w++) {
        for (int k = 1; k <= 4; k++) 
            if (w - k >= 0) J[w] = (J[w] + J[w-k]) % MOD;
    }

    for (int t = 0; t < T; t++) {
        int Nrows = nList[t], Mcols = mList[t];

        // total walls
        for (int w = 1; w <= Mcols; w++) H[w] = N(J[w], Nrows);

        // solid walls
        A[0] = 1;
        for (int w = 1; w <= Mcols; w++) {
            long long val = H[w];
            for (int cut = 1; cut < w; cut++)
                val = (val - (A[cut] * H[w-cut]) % MOD + MOD) % MOD;
            A[w] = val;
        }
        printf("%lld\n", A[Mcols]);
    }
    return 0;
}
