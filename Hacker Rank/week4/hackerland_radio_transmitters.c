#include <stdio.h>
#include <stdlib.h>

// custom comparator for qsort
int sortAsc(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
}

int minTransmitters(int arr[], int len, int range) {
    // sort house positions
    qsort(arr, len, sizeof(int), sortAsc);

    int ans = 0, idx = 0;

    while (idx < len) {
        ans++;  

        // step 1: find the furthest house we can start from
        int coverStart = arr[idx] + range;
        while (idx < len && arr[idx] <= coverStart) {
            idx++;
        }

        // step 2: place transmitter at the last possible house
        int coverEnd = arr[idx - 1] + range;
        while (idx < len && arr[idx] <= coverEnd) {
            idx++;
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int houses[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &houses[i]);
    }

    printf("%d\n", minTransmitters(houses, n, k));
    return 0;
}
