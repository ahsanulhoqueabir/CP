// https://codeforces.com/contest/1822/problem/A

#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    while (t--)
    {
          int n,a,b,c=-1,d=-1;
        scanf("%d %d",&a,&b);
          int x[a],y[a];
        for (int i=0;i<a;i++) scanf("%d",&x[i]);
        for (int i=0;i<a;i++) scanf("%d",&y[i]);

        for(int i=0;i<a;i++)
        {
            if(x[i]<=b)
            {
                if(y[i]>=d)
                {
                    c=i+1;
                    d=y[i];
                }
            }
            b--;
        }
        printf("%d\n",c);
    }
       
}