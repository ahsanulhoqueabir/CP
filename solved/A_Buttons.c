#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t); 

    for (int i = 0; i < t; i++) 
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); 
        if(a>b)
        printf("First\n");
        if(b>a)
        printf("Second\n");
        if(a==b && c%2!=0)
        printf("First\n");
        if(a==b && c%2==0)
        printf("Second\n");
    }

    return 0;
}
