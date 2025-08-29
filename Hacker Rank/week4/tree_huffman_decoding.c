#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    void decode_huff(struct node* root, char* s) {
    struct node* current = root;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
}

    return 0;
}
