#include <stdio.h>

int jhaniFindUnique(int jhaniArr[], int jhaniSize) {
    int jhaniAns = 0;
    for (int j = 0; j < jhaniSize; j++) {
        jhaniAns ^= jhaniArr[j]; 
    }
    return jhaniAns;
}

int main() {
    int jhaniCount;
    scanf("%d", &jhaniCount);
    
    int jhaniNums[jhaniCount];
    for (int k = 0; k < jhaniCount; k++) {
        scanf("%d", &jhaniNums[k]);
    }
    
    printf("%d\n", jhaniFindUnique(jhaniNums, jhaniCount));
    return 0;
}
