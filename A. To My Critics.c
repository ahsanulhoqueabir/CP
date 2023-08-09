// https://codeforces.com/contest/1850/problem/A

#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int a[3];
    for(int i=0;i<3;i++) scanf("%d",&a[i]);
    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    if(a[0]+a[1]>=10) printf("YES\n");
    else printf("NO\n");

    }

}