#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LIMIT 1000005
#define MAX_ACTIONS 100005

char *states[MAX_ACTIONS];
int stackTop = -1;

void saveState(const char *s) {
    states[++stackTop] = malloc(strlen(s) + 1);
    strcpy(states[stackTop], s);
}

void undoState() {
    if (stackTop >= 0) {
        free(states[stackTop--]);
    }
}

char* getState() {
    return (stackTop >= 0) ? states[stackTop] : "";
}

int main() {
    char buffer[STR_LIMIT] = "";
    saveState(buffer);

    int queries;
    scanf("%d", &queries);
    getchar();

    for (int i = 0; i < queries; i++) {
        char line[100];
        fgets(line, sizeof(line), stdin);

        if (line[0] == '1') {
            char *txt = line + 2;
            txt[strcspn(txt, "\n")] = '\0';
            strcat(buffer, txt);
            saveState(buffer);
        }
        else if (line[0] == '2') {
            int k = atoi(line + 2);
            int len = strlen(buffer);
            if (k <= len) buffer[len - k] = '\0';
            saveState(buffer);
        }
        else if (line[0] == '3') {
            int idx = atoi(line + 2);
            if (idx > 0 && idx <= (int)strlen(buffer)) {
                printf("%c\n", buffer[idx - 1]);
            }
        }
        else if (line[0] == '4') {
            undoState();
            strcpy(buffer, getState());
        }
    }

    while (stackTop >= 0) undoState();

    return 0;
}
