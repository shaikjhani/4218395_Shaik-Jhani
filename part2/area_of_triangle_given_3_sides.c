#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,s,area;
    printf("enter the value of 3 sides\n");
    scanf("%f%f%f",&a,&b,&c);
    s= (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("the value of s = %f",area);
    return 0 ;
    
}
