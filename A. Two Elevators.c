// https://codeforces.com/contest/1729/problem/A

#include<stdio.h>
#include<math.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int x=abs(a-1);
        int y=abs(b-c)+abs(c-1);
        if(x<y) printf("1\n");
        else if(x>y) printf("2\n");
        else printf("3\n");
    }
}