#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, Q, I = 0;  
    scanf("%d %d", &N, &Q);

    int *J[N], H[N];  
    for (int A = 0; A < N; A++) {
        J[A] = NULL;
        H[A] = 0;
    }

    while (Q--) {
        int T, X, Y, idx;
        scanf("%d %d %d", &T, &X, &Y);

        idx = (X ^ I) % N;

        if (T == 1) { 
            J[idx] = realloc(J[idx], (++H[idx]) * sizeof(int));
            J[idx][H[idx] - 1] = Y;
        } 
        else { 
            I = J[idx][Y % H[idx]];
            printf("%d\n", I);
        }
    }

    for (int A = 0; A < N; A++) {
        free(J[A]);
    }

    return 0;
}
