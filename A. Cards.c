// https://codeforces.com/problemset/problem/1220/A

#include <stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    char s[t+2];
    scanf("%s",s);
    int z=0,e=0,r=0,n=0,o=0;
    for(int i=0;i<t;i++)
    {
        if(s[i]=='z') z++;
        if(s[i]=='e') e++;
        if(s[i]=='r') r++;
        if(s[i]=='o') o++;
        if(s[i]=='n') n++;
    }
    for(int i=0;i<n;i++) printf("1 ");
    for(int i=0;i<z;i++) printf("0 ");
}
