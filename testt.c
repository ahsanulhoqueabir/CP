#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("The Series: 1 ");
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            printf("- %d ",i);
            sum-=i;
        }
        else
        {
            printf("+ %d ",i);
            sum+=i;
        }
    }
    printf("= %d",sum+1);
}

