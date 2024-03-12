// https://codeforces.com/contest/514/problem/A

#include<stdio.h>
#include<string.h>
int main()
{
    char s[20];
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        char a=s[i]-'0';
        int d= 9-(s[i]-'0');
        if(a==9 && i==0)
            printf("9");
        else if(d<a)
            printf("%d",d);
        else
            printf("%d",a);
    }
}
 