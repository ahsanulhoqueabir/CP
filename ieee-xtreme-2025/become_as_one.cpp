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
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n + 1);
    p[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        p[i] = p[i - 1] + (1LL << x);
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll s = p[r] - p[l - 1];
        if (s && (s & (s - 1)) == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
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
