#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],c[10][10],n,i,j;
    printf("Enter the size of row and colume=");
    scanf("%d",&n);
    printf("Enter the Element of Matrix[a]=");
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Enter the element of Matrix[b]=");
    printf("\n");
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {
            printf("b[%d][%d]=",i,j);
            scanf("%d",&b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("A=");
    for(i=0;i<n;i++)
    {
        printf("\t");

        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);

        }
        printf("\n");
    }
    printf("\n");
    printf("B=");
    for(i=0;i<n;i++)
    {
        printf("\t");
        for(j=0;j<n;j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    printf("A+B=");
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {
         c[i][j]=a[i][j]+b[i][j];
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\t");

        for(j=0;j<n;j++)
        {
            printf("%d",c[i][j]);

        }
        printf("\n");
    }
    printf("\n");

}
