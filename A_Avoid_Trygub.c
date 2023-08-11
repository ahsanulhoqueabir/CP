#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int l;
        scanf("%d",&l);
        char s[l+5];
        scanf("%s",s);
        for (int i = 0; i < l; i++)
        {
            for(int j=i;j<l;j++)
            {
                if(s[i]>s[j])
                {
                    char a = s[i];
                    s[i] = s[j];
                    s[j] = a;
                }
            }
        }
        printf("%s\n",s);
        
    }
    
}