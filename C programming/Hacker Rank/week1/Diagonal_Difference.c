#include <stdio.h>
#include <stdlib.h>  


int jhaniDiagDiff(int jhaniSize, int jhaniMatrix[jhaniSize][jhaniSize]) {
    int jhaniMainSum = 0, jhaniSecSum = 0;

    for (int row = 0; row < jhaniSize; row++) {
        jhaniMainSum += jhaniMatrix[row][row];
        jhaniSecSum  += jhaniMatrix[row][jhaniSize - row - 1];   
    }

    return abs(jhaniMainSum - jhaniSecSum);
}

int main() {
    int jhaniN;
    scanf("%d", &jhaniN);

    int jhaniArr[jhaniN][jhaniN];

    for (int r = 0; r < jhaniN; r++) {
        for (int c = 0; c < jhaniN; c++) {
            scanf("%d", &jhaniArr[r][c]);
        }
    }

    printf("%d\n", jhaniDiagDiff(jhaniN, jhaniArr));
    return 0;
}
