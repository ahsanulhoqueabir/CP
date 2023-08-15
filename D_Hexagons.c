#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int s=0;
    s=(((6+(6*n))*n)/2);
    printf("%lld",s+1);
}