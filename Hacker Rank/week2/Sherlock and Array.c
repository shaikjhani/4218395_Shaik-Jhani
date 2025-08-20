#include <stdio.h>

const char* balancedSums(int J[], int H) {
    long long A = 0, N = 0;

    
    for (int I = 0; I < H; I++) 
        A += J[I];

    
    for (int I = 0; I < H; I++) {
        long long right = A - N - J[I];
        if (N == right) return "YES";
        N += J[I];
    }
    return "NO";
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int H;
        scanf("%d", &H);
        int J[H];

        for (int I = 0; I < H; I++) 
            scanf("%d", &J[I]);

        printf("%s\n", balancedSums(J, H));
    }
    return 0;
}
