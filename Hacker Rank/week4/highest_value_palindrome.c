#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to form the highest value palindrome
char* makeGreatestPalindrome(char* str, int len, int ops) {
    int left = 0, right = len - 1;
    int *modified = (int*)calloc(len, sizeof(int));

    // Phase 1: Ensure palindrome property
    while (left < right) {
        if (str[left] != str[right]) {
            if (str[left] > str[right]) {
                str[right] = str[left];
            } else {
                str[left] = str[right];
            }
            modified[left] = modified[right] = 1;
            ops--;
        }
        left++;
        right--;
    }

    if (ops < 0) { // Not enough changes to form palindrome
        free(modified);
        return "-1";
    }

    // Phase 2: Maximize digits (push toward '9')
    left = 0;
    right = len - 1;
    while (left <= right) {
        if (left == right) {
            // Middle digit in odd-length string
            if (ops > 0 && str[left] != '9') {
                str[left] = '9';
            }
        } else {
            if (str[left] != '9') {
                if (modified[left] || modified[right]) {
                    // Already modified, only 1 operation needed
                    if (ops >= 1) {
                        str[left] = str[right] = '9';
                        ops--;
                    }
                } else if (ops >= 2) {
                    // Fresh modification, requires 2 ops
                    str[left] = str[right] = '9';
                    ops -= 2;
                }
            }
        }
        left++;
        right--;
    }

    free(modified);
    return str;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char *numStr = (char*)malloc((n + 1) * sizeof(char));
    scanf("%s", numStr);

    char *res = makeGreatestPalindrome(numStr, n, k);
    printf("%s\n", res);

    free(numStr);
    return 0;
}
