// https://codeforces.com/contest/1342/problem/A

#include<stdio.h>
#include<math.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        long long int x,y,a,b,m,n,s=0;
        scanf("%lld%lld\n%lld%lld",&x,&y,&a,&b);
        if(a*2>=b)
        {
            if(x<y) m=x;
            else m=y;
            s=(m*b)+(abs(x-y))*a;
            printf("%lld\n",s);
        }
        else
            printf("%lld\n",(x+y)*a);
    }
}
