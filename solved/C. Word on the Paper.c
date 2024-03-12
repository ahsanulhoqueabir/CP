// https://codeforces.com/contest/1850/problem/C

#include <stdio.h>

void word(char a[8][8])
{
    for (int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(a[j][i]!='.')
            {
                printf("%c",a[j][i]);
            }
        }
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d",&t);
    while (t--)
    {
        char a[8][8];
        for(int i=0;i<8;i++)
        {
            scanf("%s",a[i]);
        }
        word(a);
    }
}
 