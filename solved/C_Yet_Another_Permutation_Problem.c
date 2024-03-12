#include <stdio.h>
int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
    {
        long long n;
        scanf("%lld", &n);

        long long int a[200000], b[200000];
        for (long long int i = 0; i <= n; i++) 
        {
            b[i] = 0;
        }

        long long l = 0;
        for (long long int i = 1; i <= n; i++) 
        {
            if (!b[i]) 
            {
                for (long long j = i; j <= n; j *= 2) 
                {
                    b[j]++;
                    a[l++] = j;
                }
            }
    }
    for (long long int i = 0; i < l; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
    }
}
