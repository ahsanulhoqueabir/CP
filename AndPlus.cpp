#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define py cout << "Yes\n";
#define pn cout << "No\n";
void Solve()
{
    ll a, s;
    cin >> a >> s;
    ll d = s - (2 * a);
    if (d >= 0)
    {
        if ((d & a) == 0)
        {
            py return;
        }
    } pn
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}