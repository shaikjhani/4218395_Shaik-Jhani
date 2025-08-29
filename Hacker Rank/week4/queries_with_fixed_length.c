#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int *window = malloc(n * sizeof(int)); // deque of indices

    while (q--) {
        int k;
        scanf("%d", &k);

        int left = 0, right = 0;
        int answer = INT_MAX;

        // first window
        for (int i = 0; i < k; i++) {
            while (right > left && arr[window[right - 1]] <= arr[i]) right--;
            window[right++] = i;
        }
        answer = arr[window[left]];

        // slide over remaining windows
        for (int i = k; i < n; i++) {
            while (right > left && window[left] <= i - k) left++;
            while (right > left && arr[window[right - 1]] <= arr[i]) right--;
            window[right++] = i;

            if (arr[window[left]] < answer) answer = arr[window[left]];
        }

        printf("%d\n", answer);
    }

    free(window);
    free(arr);
    return 0;
}
