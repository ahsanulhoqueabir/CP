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
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<ll> pp(n + 1);
    for (ll i = 0; i < n; ++i)
    {
        pp[v[i]] = i;
    }
    auto g = [&](ll o) -> ll
    {
        vector<ll> a(n);
        for (ll k = 1; k <= n; ++k)
        {
            ll r = pp[k];
            if (o == 0)
            {
                r = r - (k - 1);
            }
            else
            {
                r = r + (k - 1);
            }
            r %= n;
            if (r < 0)
            {
                r += n;
            }
            a[k - 1] = r;
        }
        sort(a.begin(), a.end());
        vector<ll> b(2 * n);
        for (ll i = 0; i < n; ++i)
        {
            b[i] = a[i];
            b[i + n] = a[i] + n;
        }
        ll m = n;
        for (ll i = 0; i < n; ++i)
        {
            ll d = b[i + n - 1] - b[i];
            if (d < m)
            {
                m = d;
            }
        }
        return (m + 1) / 2;
    };
    ll x = g(0);
    ll y = g(1);
    cout << min(x, y) << endl;
}

int main()
{

    fraction();
    optimize();

    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    return 0;
}
