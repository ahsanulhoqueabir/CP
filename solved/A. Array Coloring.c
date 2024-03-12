// https://codeforces.com/contest/1857/problem/A

#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n; scanf("%d", &n);
        int arr[50];
        int x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i]%2==0)
            {
                x += arr[i];
            }
            else
            {
                y += arr[i];
            }
        }
        if ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
 