#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void *x, const void *y) { return (*(int *)x - *(int *)y); }
int cmpDesc(const void *x, const void *y) { return (*(int *)y - *(int *)x); }

char* checkPairs(int H, int A[], int N[], int J) {
    qsort(A, J, sizeof(int), cmpAsc);
    qsort(N, J, sizeof(int), cmpDesc);
    for (int I = 0; I < J; I++)
        if (A[I] + N[I] < H) return "NO";
    return "YES";
}

int main() {
    int J;  
    scanf("%d", &J); 
    while (J--) {
        int I, H;  
        scanf("%d %d", &I, &H); 
        int A[I], N[I];
        for (int k = 0; k < I; k++) scanf("%d", &A[k]);
        for (int k = 0; k < I; k++) scanf("%d", &N[k]);
        printf("%s\n", checkPairs(H, A, N, I));
    }
    return 0;
}
