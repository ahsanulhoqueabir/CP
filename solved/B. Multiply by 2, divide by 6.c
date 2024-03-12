// https://codeforces.com/contest/1374/problem/B

#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        long long int n,c=0,f=0; scanf("%lld",&n);
        //if(n==1) printf("0");
        while(n!=1)
        {
            if(n%6==0)
            {
                n=n/6;
                c++;
            }
            else
            {
                n=(n*2);
                c++;
            }
            if(n==0)
            {
                c=-1;
                break;
            }
        }
        printf("%lld\n",c);
    }
}