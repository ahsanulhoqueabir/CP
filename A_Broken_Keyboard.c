#include<stdio.h>
#include<string.h>

int main()
{
    int t; scanf("%d",&t);
    
    while(t--) 
    {
        char s[501];
        char s1[100]={'\0'};
        scanf("%s",s);
        int l = strlen(s);
        int j=0;
        for(int i=0;i<l;)
        {
            if(s[i]==s[i+1])
            {
                i+=2;
            }
            else
            {
                s1[j]=s[i];
                j++;
                i++;
            }
        }
        strrev(s1);
        printf("%s\n",s1);
    }
    return 0;
}