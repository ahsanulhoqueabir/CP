#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    int a[t];
    for(int i=0;i<t;i++) scanf("%d",&a[i]);
    int c=0;
    for(int i=1;i<t-1;i++)
    {
        if((a[i]<a[i-1] && a[i]<a[i+1]) || (a[i]>a[i-1] && a[i]>a[i+1]))
        {
            c++;
        }
    }
    printf("%d",c);
    
}

// a[i+1]<a[i]>a[i-1] || a[i+1]>a[i]<a[i-1]

// (a[i]<a[i-1] && a[i]<a[i+1]) || (a[i]>a[i-1] && a[i]>a[i+1])