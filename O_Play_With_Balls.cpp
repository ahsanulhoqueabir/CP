#include <bits/stdc++.h>
using namespace std;
void O_Play_With_Balls(int x)
{
    int p;
    cin >> p;
    if (p > 2)
    {
        if (p % 2 == 0)
            cout << "Case " << x << ": CodeMask\n";
        else
            cout << "Case " << x << ": CodeNewtons\n";
    }
    else
    {
        cout << "Case " << x << ": Tie\n";
    }
}
int main()
{
    int t, x;
    cin >> t;
    int q = t;
    while (t--)
    {
        O_Play_With_Balls(x = q - t);
    }
    return 0;
}