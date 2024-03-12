// https://codeforces.com/contest/1853/problem/A

#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long int a[n];
        long long int x=1000000000,y;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(i)
            {
                if(a[i]-a[i-1]< x) x= a[i]-a[i-1];
            }
        }
        if(x<0) printf("0\n");
        else printf("%lld\n",(x/2)+1);
    }
}