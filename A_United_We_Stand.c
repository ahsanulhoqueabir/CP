#include<stdio.h>
#include<string.h>
int main()
{
    int t; scanf("%d",&t);
    while(t--) 
    {
        int x,m=0,n=0; scanf("%d",&x);
        int a[x];
        for(int i=0;i<x;i++) 
        {
            scanf("%d",&a[i]);
            
        }
        int b[100000]={0},c[100000]={0};
        // int d= a[0];
        // b[0]=d;
        // for(int i=1;i<x;i++)
        // {
        //     if(a[i]==d)
        //     {
        //         b[m]=a[i];
        //         m++;
        //     }
        //     else
        //     {
        //         c[n]=a[i];
        //         n++;
        //     }
        // }
        for(int i=0;i<x;i++)
        {
            if(a[i]%2==0)
            {
                b[m]=a[i];
                m++;
            }
            else
            {
                c[n]=a[i];
                n++;
            }
        }
       // printf("%d\n",b[0]);
        //if(n==0) printf("-1\n");
        if(m==0 && n>0)
        {
            int max= c[0];
            for(int i=1;i<n;i++)
            {
                if(c[i]>max) max=c[i];
                printf("1 %d\n",n-1);
                printf("%d\n",max);
                for(int i=0;i<n;i++)
                {
                    if(c[i]==max) continue;
                    else
                    printf("%d ",c[i]);
                }
                printf("\n");
            }
        }
        else if(n==0 && m>0)
        {
            int max= b[0];
            for(int i=1;i<m;i++)
            {
                if(b[i]>max) max=b[i];
                printf("1 %d\n",m-1);
                printf("%d\n",max);
                for(int i=0;i<m;i++)
                {
                    if(b[i]==max) continue;
                    else
                    printf("%d ",b[i]);
                }
                printf("\n");
            }
        }
       else  if(n==0 ||  m==0) printf("-1\n");
        else 
        {
            printf("%d %d\n",m,n);
            for(int i=0;i<m;i++) printf("%d ",b[i]); printf("\n");
            for(int i=0;i<n;i++) printf("%d ",c[i]); printf("\n");

        }
        
    }
    return 0;
}