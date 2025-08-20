#include <stdio.h>

int J(unsigned long long H) {
    return (H && !(H & (H - 1))); 
}

unsigned long long H_pow(unsigned long long H) {
    unsigned long long A = 1ULL;
    while ((A << 1ULL) <= H) 
        A <<= 1ULL;
    return A;
}

const char* A_game(unsigned long long H) {
    int N = 0;
    while (H != 1ULL) {
        if (J(H)) {
            H >>= 1ULL; 
        } else {
            H -= H_pow(H); 
        }
        N++;
    }
    return (N % 2) ? "Louise" : "Richard";
}

int main() {
    int I;
    scanf("%d", &I);
    while (I--) {
        unsigned long long H;
        scanf("%llu", &H);
        printf("%s\n", A_game(H));
    }
    return 0;
}
