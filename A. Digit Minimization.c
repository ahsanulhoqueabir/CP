// https://codeforces.com/contest/1684/problem/A

#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[20];
        scanf("%s",s);
        int l=strlen(s);
        if(l<=2)
            printf("%c\n",s[1]);
        else
        {
        char min=s[0];
        for(int i=1;i<l;i++)
        {
            if(s[i]<min)
            {
                min=s[i];
            }
        }
        printf("%c\n",min);
        }
    }
}