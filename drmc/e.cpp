#include <bits/stdc++.h>
using namespace std;
// #define double double;
void e(int pos)
{
    double p, q, x, y;
    int ans = 1;

    cin >> p >> q;
    x = p;
    y = q;

    while (x >= y)
    {
        p /= 2;
        x += p;
        y += q;
        ans++;
    }
    cout << "Case #" << pos << ": " << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        e(i + 1);
    }

    return 0;
}