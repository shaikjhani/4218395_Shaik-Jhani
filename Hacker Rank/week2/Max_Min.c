#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare_J(const void *H, const void *A) {
    return (*(int *)H - *(int *)A);
}

int main() {
    int N, I;
    scanf("%d%d", &N, &I);

    int J_arr[N];
    for (int H = 0; H < N; H++) {
        scanf("%d", &J_arr[H]);
    }

    
    qsort(J_arr, N, sizeof(int), compare_J);

    int unfairness_A = J_arr[I - 1] - J_arr[0];
    for (int H = 1; H <= N - I; H++) {
        int gap_N = J_arr[H + I - 1] - J_arr[H];
        if (gap_N < unfairness_A) {
            unfairness_A = gap_N;
        }
    }

    printf("%d\n", unfairness_A);
    return 0;
}
