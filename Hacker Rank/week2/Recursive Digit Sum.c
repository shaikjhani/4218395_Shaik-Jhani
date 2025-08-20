#include <stdio.h>
#include <string.h>

long long digitSum(long long num) {
    if (num < 10) return num;
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return digitSum(sum);
}

int main() {
    char n[100001];
    int k;
    scanf("%s %d", n, &k);

    long long sum = 0;
    for (int i = 0; i < strlen(n); i++)
        sum += n[i] - '0';  

    sum *= k;  
    printf("%lld\n", digitSum(sum));
    return 0;
}
