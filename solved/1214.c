#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--) 
    {
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        if(a%b == 0) printf("Divisible\n");
        else printf("not divisible\n");

        printf("%d\n",a%b);


    }
    return 0;
}