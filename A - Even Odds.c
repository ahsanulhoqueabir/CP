// https://codeforces.com/contest/318/problem/A


#include<stdio.h>
int main()
{
    long long int n,k;
    long long int x,y,z;
    scanf("%lld%lld",&n,&k);
    x= n/2;
    y= n-x;

    if( k> y)
    {
        k-=y;
        z=k*2;
    }
    else
    {
        z=(k*2)-1;
    }
    printf("%lld",z);
}
