// https://codeforces.com/contest/1845/problem/A

#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,x;
        scanf("%d%d%d",&n,&k,&x);
        if(k==1)
            printf("NO\n");
        else
        {
            if(x!=1)
            {
                printf("YES\n%d\n",n);
                for(int i=1;i<=n;i++)
                {
                    printf("1");
                    if(i!=n) printf(" ");
                    //else printf()
                }
                printf("\n");
            }
            else
            {
                if(n%2==0)
                {
                    printf("YES\n%d\n",n/2);
                    for(int i=1;i<=n/2;i++)
                    {
                        printf("2");
                        if(i!=n/2) printf(" ");
                    }
                    printf("\n");
                }
                else
                {
                    if(k==2) printf("NO\n");
                    else
                    {
                      printf("YES\n%d\n 3",(n-3)/2 +1);
                    for(int i=1;i<=(n-3)/2;i++)
                    {
                        printf(" 2");
                        //if(i!=n-3/2) printf(" ");
                    }
                    printf("\n");
                    }
                }
            }
        }

    }
}