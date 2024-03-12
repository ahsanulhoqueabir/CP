// https://codeforces.com/contest/887/problem/A

#include<stdio.h>
#include<string.h>
int main()
{
    char s[110];
    scanf("%s",s);
    int l=strlen(s);
    int x=0,y=0,c=0;
    for(int i=0;i<l-3;i++)
    {
        if(s[i]=='0') c++;
        else break;
    }
    //printf("%d",c);
    for(int i=c;i<=l;i++)
    {
        if(s[i]=='0') x++;
        //else y++;
    }
    if(x>5) printf("yes\n");
    else printf("no\n");
}
