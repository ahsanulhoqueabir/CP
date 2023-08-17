#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int a[n];
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<n;i++)
        {
            long long int max=0;
            for(int j=0;j<n;)
            {
                if(j==i) j++;
                else
                {
                    if(a[j]>max) max= a[j];
                    j++;
                }

            }
            printf("%lld ",a[i]-max);
        }
    printf("\n");
    }
    
}

