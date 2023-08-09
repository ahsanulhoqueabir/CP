#include <stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n,result;
    int sum=0,a,b,c=0,t,l;
    char s,s1;
    printf("Enter the string: ");
    gets(s);
    l=strlen(s);
    s1=s;
    strrev(s);
    c=strcmp(s,s1);
    if(c==0) printf("YES");
    else printf("NO");
    
    
return 0;
}