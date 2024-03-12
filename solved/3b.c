#include <stdio.h>
int main()
{
    int num = 0, x = 1;
    while (num <= 8)
    {

        switch (num)
        {
        case 0:
            x = 0;
            printf("%d\n", x);
        case 1:
            num += 1;
            break;
        case 2:
            x = 2;
            printf("%d\n", x);
        case 3:
            printf("%d\n", x * 2);
            x = x + 1;
            num = num + 5;
            printf("%d\n", x);
            break;
        default:
            num = num * 2; 
            printf("%d\n", num);
        }
    }
}