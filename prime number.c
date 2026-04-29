#include<stdio.h>
int main()
{
    int i,n,f=0;
    printf("Enter n=");
    scanf("%d",&n);
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            f=1;
            break;
        }
    }
    if(f==0 && n!=1)
    {
        printf("%d is prime number",n);
    }
    else
    {
        printf("%d is not prime number",n);
    }
    return 0;
}