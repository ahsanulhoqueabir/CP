#include<stdio.h>
int main()
{
    int k,r;
    scanf("%d %d",&k,&r);
    for(int i=1;;i++)
    {
        if((i*k)%10 == 0 || ((i*k)-r)%10==0)
        {
            printf("%d",i);
            break;
        }
        else continue;
    }
}
