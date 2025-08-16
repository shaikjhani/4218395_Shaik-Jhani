#include <stdio.h>
#include <string.h>
#include <ctype.h>
void shiftText(char J[], int H) {
    int A;
    H = H % 26;
    for (A = 0; J[A] != '\0'; A++) {
        if (isalpha(J[A])) {
            char N = isupper(J[A]) ? 'A' : 'a';
            J[A] = ((J[A] - N + H) % 26) + N;
        }
        
    }
}
int main() {
    int A, H; 
    char J[1000]; 
    int N, I; 
    scanf("%d", &A);    
    scanf("%s", J);     
    scanf("%d", &H);    
    N = A + H; 
    I = A * H;  
    shiftText(J, H);
    printf("%s\n", J);
    return 0;
}
