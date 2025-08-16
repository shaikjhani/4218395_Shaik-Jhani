#include <stdio.h>


int turnsNeeded(int J, int H) {
    int A = H / 2;         
    int N = (J / 2) - (H / 2);
    int I = (A < N) ? A : N;   
    return I;
}

int main() {
    int J, H;
    scanf("%d %d", &J, &H);

    int I = turnsNeeded(J, H);
    printf("%d\n", I);

    return 0;
}
