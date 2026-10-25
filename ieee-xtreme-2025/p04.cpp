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

ll mod(ll x, ll m)
{
    x %= m;
    if (x < 0)
        x += m;
    return x;
}

ll mod_pow(ll b, ll e, ll m)
{
    ll ans = 1;
    b = mod(b, m);
    while (e)
    {
        if (e & 1)
            ans = mod(ans * b, m);
        b = mod(b * b, m);
        e >>= 1;
    }
    return ans;
}

ll mod_inverse(ll value, ll mod_value)
{
    return mod_pow(value, mod_value - 2, mod_value);
}

void Solve()
{
    ll a, b, p;
    ll x1, y1, x2, y2;
    cin >> a >> b >> p >> x1 >> y1 >> x2 >> y2;

    ll lam = 0;

    if (x1 == x2 && mod(y1 + y2, p) == 0)
    {
        cout << "POINT_AT_INFINITY" << endl;
        return;
    }

    if (x1 == x2 && y1 == y2)
    {
        ll nm = mod(3 * x1 * x1 + a, p);
        ll dm = mod(2 * y1, p);
        if (dm == 0)
        {
            cout << "POINT_AT_INFINITY" << endl;
            return;
        }
        lam = mod(nm * mod_inverse(dm, p), p);
    }
    else
    {
        ll nm = mod(y2 - y1, p);
        ll dm = mod(x2 - x1, p);
        if (dm == 0)
        {
            cout << "POINT_AT_INFINITY" << endl;
            return;
        }
        lam = mod(nm * mod_inverse(dm, p), p);
    }

    ll x3 = mod(lam * lam - x1 - x2, p);
    ll y3 = mod(lam * (x1 - x3) - y1, p);

    cout << x3 << " " << y3 << endl;
}

int main()
{

    fraction();
    optimize();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    return 0;
}
