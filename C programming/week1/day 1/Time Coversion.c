#include <stdio.h>
#include <string.h>

void convertTo24HourFormat(const char *inputTime) {
    int hour, minute, second;
    char period[3];
    char output[9];

    sscanf(inputTime, "%2d:%2d:%2d%2s", &hour, &minute, &second, period);

    if (strcmp(period, "AM") == 0 && hour == 12) {
        hour = 0;
    } else if (strcmp(period, "PM") == 0 && hour != 12) {
        hour += 12;
    }

    snprintf(output, sizeof(output), "%02d:%02d:%02d", hour, minute, second);
    printf("24-hour time: %s\n", output);
}

int main() {
    char timeInput[11];

    printf("Enter time in 12-hour format (hh:mm:ssAM/PM):\n");
    scanf("%s", timeInput);

    convertTo24HourFormat(timeInput);

    return 0;
}
