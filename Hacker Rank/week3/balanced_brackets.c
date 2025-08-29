#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* checkBrackets(char *s) {
    int n = strlen(s), top = -1;
    char *stk = malloc(n);

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c=='(' || c=='[' || c=='{') {
            stk[++top] = c;
        } else {
            if (top < 0) { free(stk); return "NO"; }
            char last = stk[top--];
            if ((c==')' && last!='(') || 
                (c==']' && last!='[') || 
                (c=='}' && last!='{')) {
                free(stk);
                return "NO";
            }
        }
    }
    free(stk);
    return (top==-1) ? "YES" : "NO";
}

char* trim(char* s) {
    while(isspace(*s)) s++;
    if(!*s) return s;
    char *end = s + strlen(s)-1;
    while(end > s && isspace(*end)) *end-- = '\0';
    return s;
}

char* readLine() {
    size_t sz = 1024, len = 0;
    char *buf = malloc(sz);
    while (fgets(buf+len, sz-len, stdin)) {
        len += strlen(buf+len);
        if (buf[len-1]=='\n') { buf[len-1]='\0'; break; }
        sz *= 2;
        buf = realloc(buf, sz);
    }
    return buf;
}

int main() {
    int t; scanf("%d\n", &t);
    while (t--) {
        char *str = trim(readLine());
        printf("%s\n", checkBrackets(str));
        free(str);
    }
    return 0;
}
