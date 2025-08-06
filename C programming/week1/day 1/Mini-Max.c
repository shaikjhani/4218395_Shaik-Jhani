#include <stdio.h>

void calculateMiniMaxSums(const int numbers[5]) {
    long totalSum = 0;
    int smallest = numbers[0];
    int largest = numbers[0];

    for (int i = 0; i < 5; ++i) {
        int current = numbers[i];
        totalSum += current;

        if (current < smallest) {
            smallest = current;
        }
        if (current > largest) {
            largest = current;
        }
    }

    long minSum = totalSum - largest;
    long maxSum = totalSum - smallest;

    printf("Minimum Sum: %ld, Maximum Sum: %ld\n", minSum, maxSum);
}

int main() {
    int data[5];

    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &data[i]);
    }

    calculateMiniMaxSums(data);

    return 0;
}
