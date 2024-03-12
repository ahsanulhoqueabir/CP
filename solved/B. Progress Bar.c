// https://codeforces.com/contest/71/problem/B

#include<stdio.h>
int main()
{
    int n,k,t;
    scanf("%d%d%d",&n,&k,&t);
    long long int s=(n*k*t)/100;
    for(int i=0;i<n;i++)
    {
        if(s>=k)
        {
           s=s-k;
           printf("%d ",k);
        }
        else if(s<k && s>0)
        {
            printf("%d ",s);
            s=s-k;
        }
        else printf("0 ");
    }
}