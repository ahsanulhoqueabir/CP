// https://codeforces.com/contest/1095/problem/A

#include<stdio.h>
#include<string.h>
int main()
{
    int n,d=1; scanf("%d",&n);
    char s[n+5]; scanf("%s",s);
    for(int i=0;i<=n;)
    {
        printf("%c",s[i]);
        d++;
        i+=d;
    }
}