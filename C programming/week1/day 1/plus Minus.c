#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int pos = 0, neg = 0, zero = 0;

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > 0)
            pos++;
        else if (arr[i] < 0)
            neg++;
        else
            zero++;
    }

    // Calculate and print ratios with 6 decimal places
    printf("%.6f\n", (float)pos / n);
    printf("%.6f\n", (float)neg / n);
    printf("%.6f\n", (float)zero / n);

    return 0;
}
