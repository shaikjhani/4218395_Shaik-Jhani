#include <stdio.h>
#include <string.h>

void convertTimeTo24Hour(char *time12h) {
    int hours;
    char suffix[3];
    char finalTime[9];

    
    sscanf(time12h, "%2d:%*2d:%*2d%2s", &hours, suffix);

    
    if (strcmp(suffix, "AM") == 0 && hours == 12) {
        hours = 0;
    } else if (strcmp(suffix, "PM") == 0 && hours != 12) {
        hours += 12;
    }

    
    sprintf(finalTime, "%02d", hours);
    strncat(finalTime, time12h + 2, 6); 

    printf("%s\n", finalTime);
}

int main() {
    char userTime[11]; 
    scanf("%s", userTime);

    convertTimeTo24Hour(userTime);

    return 0;
}
