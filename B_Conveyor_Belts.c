#include<stdio.h>
#include<math.h>
int main()
{
    int t; scanf("%d",&t);
    while (t--)
    {
        int n, a, b, c, d,p,q,r,s,t,m1,m2,m3,m4,x,y;
        scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        // int x = min(min(a, n - a + 1), min(b, n - b + 1)), y = min(min(c, n - c + 1), min(d, n - d + 1));
		// cout << abs(x - y) << endl;
        p=n-a+1;
        if(a<p) m1=a;
        else m1= p;

        q= n-b+1;
        if(b<q) m2=b;
        else m2=q;

        if(c< (n-c+1)) m3=c;
        else m3=n-c+1;

        if(d< (n-d+1)) m4=d;
        else m4= n-d+1;
        
        if(m1<m2) x=m1;
        else x=m2;

        if(m3<m4) y= m3;
        else y=m4;
        
        // int s=x-y;
        ((x-y)>0) ? s=x-y : s=y-x;
        printf("%d",s);
    }
    
}