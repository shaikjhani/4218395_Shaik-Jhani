#include <stdio.h>

void findMinMaxTotals(int input[5]) {
    long sum = 0;
    int minVal = input[0];
    int max = input[0];

    for (int index = 0; index < 5; index++) {
        sum += input[index];

        if (input[index] < minVal)
            minVal = input[index];
        if (input[index] > max)
            max = input[index];
    }

    long minTotal = sum - max;
    long maxTotal = sum - minVal;

    printf("%ld %ld\n", minTotal, maxTotal);
}

int main() {
    int values[5];

    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &values[i]);
    }

    findMinMaxTotals(values);

    return 0;
}
