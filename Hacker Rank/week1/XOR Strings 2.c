#include <stdio.h>
#include <string.h>

int main() {
    char s[1001], t[1001], res[1001];
    scanf("%s", s);
    scanf("%s", t);

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        res[i] = (s[i] == t[i]) ? '0' : '1';
    }
    res[len] = '\0';

    printf("%s", res);  // No newline, per strict output requirement

    return 0;
}