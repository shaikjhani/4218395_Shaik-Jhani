#include <stdio.h>

void analyzeNumberDistribution(int *list, int count) {
    int positives = 0, negatives = 0, zeros = 0;

    for (int i = 0; i < count; ++i) {
        if (list[i] > 0)
            positives++;
        else if (list[i] < 0)
            negatives++;
        else
            zeros++;
    }

    printf("Positive Ratio: %.6f\n", (float)positives / count);
    printf("Negative Ratio: %.6f\n", (float)negatives / count);
    printf("Zero Ratio: %.6f\n", (float)zeros / count);
}

int main() {
    int total;

    printf("How many numbers will you enter?\n");
    scanf("%d", &total);

    int numbers[total];

    printf("Enter the numbers:\n");
    for (int i = 0; i < total; ++i) {
        scanf("%d", &numbers[i]);
    }

    analyzeNumberDistribution(numbers, total);

    return 0;
}
