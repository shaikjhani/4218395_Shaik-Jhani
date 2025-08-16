#include <stdio.h>
int decideChampion(int J, int H) {
    
    
    if (H == 1 || J % 2 == 0) {
        return 2; 
    }
    return 1; 
}
int main() {
    int A; 
    scanf("%d", &A);
    while (A--) {
        int J, H; 
        int N, I; 
        scanf("%d %d", &J, &H);
        N = J + H;
        I = J * H;
        printf("%d\n", decideChampion(J, H));
    }

    return 0;
}
