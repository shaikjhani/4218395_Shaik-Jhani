#include <stdio.h>
#include <string.h>

#define JHANI_LIMIT 1000
#define JHANI_SIZE 101

void jhaniInputStrings(char jhaniArr[][JHANI_SIZE], int jhaniCount) {
    for (int jhaniIndex = 0; jhaniIndex < jhaniCount; jhaniIndex++) {
        scanf("%s", jhaniArr[jhaniIndex]);
    }
}

int jhaniCountMatches(const char *jhaniTarget, char jhaniArr[][JHANI_SIZE], int jhaniCount) {
    int jhaniTotal = 0;
    for (int jhaniIndex = 0; jhaniIndex < jhaniCount; jhaniIndex++) {
        if (strcmp(jhaniTarget, jhaniArr[jhaniIndex]) == 0) {
            jhaniTotal++;
        }
    }
    return jhaniTotal;
}

int main() {
    int jhaniDataCount, jhaniQueryCount;
    char jhaniData[JHANI_LIMIT][JHANI_SIZE];
    char jhaniQueries[JHANI_LIMIT][JHANI_SIZE];

    
    scanf("%d", &jhaniDataCount);
    jhaniInputStrings(jhaniData, jhaniDataCount);

    
    scanf("%d", &jhaniQueryCount);
    jhaniInputStrings(jhaniQueries, jhaniQueryCount);

    
    for (int jhaniI = 0; jhaniI < jhaniQueryCount; jhaniI++) {
        printf("%d\n", jhaniCountMatches(jhaniQueries[jhaniI], jhaniData, jhaniDataCount));
    }

    return 0;
}
