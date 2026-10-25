#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(6);            \
    cout.setf(ios::fixed, ios::floatfield);

void Solve()
{
    ll n;
    cin >> n;
    ll m = 998244353;
    if (n % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll r = 1;
    ll p = n % m;
    ll e = m - 2;
    while (e > 0)
    {
        if (e & 1)
        {
            r = (r * p) % m;
        }
        p = (p * p) % m;
        e >>= 1;
    }
    cout << r % m << endl;
}

int main()
{

    fraction();
    optimize();

    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        Solve();
    }

    return 0;
}
