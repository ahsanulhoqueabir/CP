#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    // for (int i = 0; i <= c / a; i++) 
    // {
        // if ((c - i * a) % b == 0) 
        // {
    //         printf("Yes\n");
    //     }
    // }
    
    // printf("No\n");

    int count =0;
    for(int i=0;;i++)
    {
        if(a*i > c)
        {
            break;
        }
        for(int j=0;;j++)
        {
            int s= i*a + j*b;
            if(s==c)
            {
                count=1;
            }
            if(s>c)
            {
                break;
            }
        }
    }
    if(count == 0) printf("No");
    else printf("Yes");
}