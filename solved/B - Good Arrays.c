// https://codeforces.com/contest/1856/problem/B

#include<stdio.h>
int main()
{
    int t ; scanf("%d",&t);
    while(t--)
    {
    int n; scanf("%d",&n);
    long long int s =0,r=0;
    for(int i=0;i<n;i++)
    {
        int x; scanf("%d",&x);
        s+=x;
        if( x == 1) r+=2;
        else r+=1;
    }
    if( n==1 || r>s) printf("NO\n");
    else printf("YES\n");
    }

}
