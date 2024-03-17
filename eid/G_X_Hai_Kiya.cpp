#include <bits/stdc++.h>
using namespace std;

bool Check(int a, int b, int c)
{
    int ca = 0;
    for (int i = 0; i <= 27; i++)
    {
        int b1 = (a >> i) & 1;
        int b2 = (b >> i) & 1;
        int b3 = (c >> i) & 1;
        if (b1 == b2 && b2 != b3)
            ca ^= 1;
    }
    return ca;
}
void G_X_Hai_Kiya()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b) == c)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        if (Check(a, b, c))
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        G_X_Hai_Kiya();
    return 0;
}