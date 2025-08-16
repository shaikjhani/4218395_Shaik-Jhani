#include <stdio.h>

int jhani(int J[], int H, int A, int N) {
    int I = 0;
    for (int h = 0; h <= H - N; h++) { 
        int sum = 0;
        for (int a = 0; a < N; a++) { 
            sum += J[h + a];
        }
        if (sum == A) {
            I++;
        }
    }
    return I;
}

int main() {
    int H;
    scanf("%d", &H);

    int J[H];
    for (int n = 0; n < H; n++) {
        scanf("%d", &J[n]);
    }

    int A, N;
    scanf("%d %d", &A, &N);

    printf("%d\n", jhani(J, H, A, N));
    return 0;
}
