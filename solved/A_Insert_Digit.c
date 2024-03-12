#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--) 
    {
        int l,a,c=0;
        scanf("%d %d",&l,&a);
        char s[l+5];
        scanf("%s",s);
        for(int i=0;i<l;i++)
        {
            int d = s[i]-'0';
            if(d < a && c==0) 
            {
                printf("%d",a);
                c=1;
            }
            printf("%c",s[i]);
        }
        if(c==0)
        {
            printf("%d",a);
        }
        
        printf("\n");
    }
    return 0;
}