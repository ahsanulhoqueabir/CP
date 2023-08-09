// https://codeforces.com/contest/1850/problem/B

#include <stdio.h>
int f(int w[], int q[], int n)
{
    int m = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[i]<=10&&q[i]>m)
        {
            m=q[i];
            r=i+1;
        }
    }
    return r;
}

int main()
{
    int t; scanf("%d",&t);
    while (t--)
    {
        int n; scanf("%d",&n);
        int w[n];
        int q[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&w[i],&q[i]);
        }
        int r=f(w,q,n);
        printf("%d\n",r);
    }
}
 