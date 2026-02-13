#include<stdio.h>
int main()
{
    int a,b,c;
    char oper;
    printf("Enter operator \n");
    scanf("%c",&oper);
    printf("enter a and b values \n");
    scanf("%d%d",&a,&b);
    switch(oper)
    {
        case '+':
        c = a+b;
        printf("sum=%d",c);
        break;

        case '-':
        c = a-b;
        printf("SUB=%d",c);
        break;

        case '*':
        c = a*b;
        printf("mul=%d",c);
        break;

        case '/':
        c = a/b;
        printf("DIV=%d",c);
        break;

        default:
        printf("Try again with different combinations ");
    }

}
