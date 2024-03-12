// https://codeforces.com/problemset/problem/1436/A

#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n],s=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
     if(s==m) printf("YES\n");
     else printf("NO\n");
    }
}
