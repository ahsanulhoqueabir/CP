#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--) 
    {
        long long int a,b,s,r,f=1;
        scanf("%lld %lld",&a,&b);
        s=2*a*b;
        for(long long int i=1;;i++)
        {
            if(i*i >=s)
            {
                r=i*i;
                break;
            }
        }
        printf("%lld\n",r);
    }
    return 0;
}