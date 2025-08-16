#include <stdio.h>
#include <stdlib.h>

int compare(const void *J, const void *H) {
    
    return (*(int *)J - *(int *)H);
}

int findPairs(int A, int N[]) {
    qsort(N, A, sizeof(int), compare);
    int I = 0;

    for (int H = 0; H < A - 1; ) {
        if (N[H] == N[H + 1]) {
            I++;        
            H += 2;     
        } else {
            H++;
        }
    }
    return I;
}

int main() {
    int J; 
    scanf("%d", &J);

    int H[J]; 

    for (int A = 0; A < J; A++) {
        scanf("%d", &H[A]);
    }

    int I = findPairs(J, H);
    printf("%d\n", I);

    return 0;
}