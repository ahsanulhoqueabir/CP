#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    while (t--)
    {
       int n,i=0;
       scanf("%d",&n);
       int a[]={0};
       int c=0;
       while(n!=0)
       {
         int tmp = n%2;
         if(tmp==1) c++;
         n /= 2;
       }
       printf("%d",c);
    }
    


    return 0;
}