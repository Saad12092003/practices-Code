#include<stdio.h>
int main()
{
    float a,b;
    char c;
    printf("Enter a=");
    scanf("%f",&a);
    printf("Enter b=");
    scanf("%f",&b);
    printf("Enter operator=");
    getchar();
    scanf("%c",&c);
    switch(c)
    {
    case '+':
        printf("addition =%.2f",a+b);
        break;
    case '-':
        printf("subtruction=%.2f",a-b);
          break;

    case '*':
        printf("product=%.2f",a*b);
          break;
    case '/':
        printf("division=%.2f",a/b);
          break;
    default:
        printf("Error");

    }
    return 0;
}