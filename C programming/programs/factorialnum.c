#include<stdio.h>
int main()
{
    int i,n,fact=1;
    printf("enter a number ");
    scanf("%d",&n);
    for (i=1;i<=n;i++) /*flow of i first i=1; checks 1<=n true . fact=1 intalized now fact *i => 1*1=1 after that i++ means now i=2
                        second iteration i=2 checks i<=n fact (1) = 1*2 now fact is 3 again i++ now i =3
                        3 time i=3 i<=n fact(2)= 2*3 => fact now (6) i++ now 4
                        4th time i=4;i<=n fact (6) = 6*4 = 24 agian i++ = 5
                        5th time i=5;i<=n(5) fact (24) = 24*5=> 120 again i++ 
                        6th time i=6;i(6)<=n(5) fasle loop exits*/
    {
        fact = fact * i;
    }
    printf("FActorila of a given number = %d",fact);
    return 0;
}