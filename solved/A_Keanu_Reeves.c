#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    //while(t--) 
    //{
        char s[105];
        scanf("%s",s);
        int l=strlen(s),c=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='0') c++;
        }
        if(c!= l/2 || (l%2 && l/2==c))
        {
            printf("1\n%s",s);
        }
        else
        {
            printf("2\n");
            printf("%c ",s[0]);
            for(int i=1;i<l;i++) 
            {
                printf("%c",s[i]);
            }
        }
        printf("\n");
   // }
    return 0;
}