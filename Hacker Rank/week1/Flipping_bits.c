#include <stdio.h>
#include <stdint.h> 

unsigned int flippingBits(unsigned int n) {
    return ~n & 0xFFFFFFFF;
}

int main() {
    int q;
    scanf("%d", &q);  
    while (q--) {
        unsigned int n;
        scanf("%u", &n);  

        unsigned int result = flippingBits(n);
        printf("%u\n", result);
    }

    return 0;
}
