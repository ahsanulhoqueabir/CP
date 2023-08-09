// https://codeforces.com/contest/1840/problem/A

#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char s[101];
        scanf("%s",s);
        char c=s[0];
        printf("%c",c);
        for(int i=1;i<strlen(s)-1;i++)
        {
            if(s[i]==c)
            {
                c=s[i+1];
                i++;
                printf("%c",c);
            }
        }
        printf("\n");
    }
}