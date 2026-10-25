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

const ll M = 1000000007;
vector<array<int, 4>> c;

ll H(vector<ll> &v)
{
    for (int i = 0; i < 4; i++)
        if (v[i] < 0)
            return 0;
    vector<vector<ll>> dp(61, vector<ll>(16, -1));
    function<ll(int, int)> g = [&](int p, int m) -> ll
    {
        if (p < 0)
            return 1;
        ll &u = dp[p][m];
        if (u != -1)
            return u;
        ll r = 0;
        for (auto &y : c)
        {
            int ok = 1;
            int nm = 0;
            for (int i = 0; i < 4; i++)
            {
                int t = (m >> i) & 1;
                int xb = (int)((v[i] >> p) & 1);
                if (t)
                {
                    if (y[i] > xb)
                    {
                        ok = 0;
                        break;
                    }
                    if (y[i] == xb)
                        nm |= (1 << i);
                }
            }
            if (!ok)
                continue;
            r += g(p - 1, nm);
            if (r >= M)
                r -= M;
        }
        u = r;
        return u;
    };
    return g(60, 15);
}

void Solve()
{
    if (c.empty())
    {
        for (int m = 0; m < 16; m++)
            if ((__builtin_popcount(m) & 1) == 0)
            {
                array<int, 4> y;
                for (int i = 0; i < 4; i++)
                    y[i] = (m >> i) & 1;
                c.push_back(y);
            }
    }
    int q;
    cin >> q;
    while (q--)
    {
        vector<ll> l(4), r(4);
        for (int i = 0; i < 4; i++)
            cin >> l[i] >> r[i];
        ll z = 0;
        for (int m = 0; m < 16; m++)
        {
            vector<ll> v(4);
            int s = 0;
            for (int i = 0; i < 4; i++)
                if ((m >> i) & 1)
                {
                    v[i] = l[i] - 1;
                    s ^= 1;
                }
                else
                    v[i] = r[i];
            ll w = H(v);
            if (s)
            {
                z -= w;
                if (z < 0)
                    z += M;
            }
            else
            {
                z += w;
                if (z >= M)
                    z -= M;
            }
        }
        ll tt = 1;
        for (int i = 0; i < 4; i++)
        {
            ll d = (r[i] - l[i] + 1) % M;
            if (d < 0)
                d += M;
            tt = (tt * d) % M;
        }
        ll an = (tt - z + M) % M;
        cout << an << endl;
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
