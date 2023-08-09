// https://codeforces.com/contest/1855/problem/A

#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int a[n];
        int c=0;
        for(int i=1;i<=n;i++)
        {
           scanf("%d",&a[i]);
           if(a[i]==i) c++;
        }
        printf("%d\n",(c+1)/2);
    }
}