#include<stdio.h>
int main()
{
    long long int n,c;
    scanf("%lld",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n/3;i++)
	{
		if(n%i==0)
			for(int j=0;j<i;j++)
			{
				int k=j;
				while(a[k] && k<n) 
                    k=k+i;
				if(k>=n)
				{
					printf("YES\n");
					return 0;
				}
			}
	}
	printf("NO\n");

return 0;
}