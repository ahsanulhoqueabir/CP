// https://codeforces.com/contest/1820/problem/A

#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[101];
        scanf("%s",s);
        int l=strlen(s);
        int a=0,b=0;
        if(l==1 && s[l-1]=='^')
            printf("1\n");
        else
        {
            if(s[0]!='^') a=1;
            if(s[l-1]!='^') b=1;
            int c=0;
            for(int i=0;i<l;i++)
            {
                if(s[i]=='_' && s[i+1]=='_') c++;
            }
        printf("%d\n",c+a+b);
        }
    }
}