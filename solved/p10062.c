#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF);
    {
    int a[256]={0};
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        int d = s[i];
       // printf("%d\n",d);
       a[d]++;
    }
    
    // for(int i=1;i<=256;i++)
    // {
    //     if(a[i]>0 && (i>='A'&&i<='Z' || i>='a' && i<='z' || i>='0' && i<='9'))
    //     {
    //         printf("%d %d\n",i,a[i]);
    //     }
    // }
    for(int i=1;i<=l;i++)
    {
        for(int j=128;j>0;j--)
        {
            if(a[j]==i)
            printf("%d %d\n",j,a[j]);
        }
    }
    }
    printf("\n");
}