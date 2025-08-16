#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* JHANI(char J[]) {
    int H[26] = {0};  
    int A, N;

    for (A = 0; J[A] != '\0'; A++) {
        char I = tolower((unsigned char)J[A]);
        if (I >= 'a' && I <= 'z') {
            H[I - 'a'] = 1;
        }
    }

    for (N = 0; N < 26; N++) {
        if (!H[N]) return "not pangram";
    }
    return "pangram";
}

int main() {
    char J[1000];
    fgets(J, sizeof(J), stdin);
    J[strcspn(J, "\n")] = '\0';
    printf("%s\n", JHANI(J));
    return 0;
}
