#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    char s[t][35];
    for(int i=0;i<t;i++)
    {
        scanf("%s",s[i][35]);
    }
    for(int i=0;i<t;i++)
    {
        int c=0;
        for(int j=1;j<i;j++)
        {
            int d= strcmp(s[i][35],s[j][35]);
            if(d == 0)
            {
                //printf("%s%d\n",s[i][35],c);
                c++;
            }
            else
            {
                printf("ok\n");
            }
        }
    }

    return 0;
}