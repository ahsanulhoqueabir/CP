// https://codeforces.com/contest/1551/problem/A

#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a,b;
        if(n%3==0) printf("%d %d\n",n/3,n/3);
        else
        {
            a=(n/3)+1;
            b=n/3;
            if(a+(2*b)>n || a+(2*b)<n)
            {
                a=n/3;
                b=(n/3)+1;
            }
            printf("%d %d\n",a,b);
        }
    }
}
