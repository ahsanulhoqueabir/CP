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
    long double sd;
    ll nn;
    cin >> sd >> nn;
    vector<vector<int>> v(2);
    long double f = 0;
    long double na = 0;
    long double ng = 0;
    long double a = -19;
    long double tg = sd * sd;
    __int128 r = -19;
    const __int128 c = (__int128)9223372036854775807LL + 14;
    while (a < tg)
    {
        na += 1.0L / 19.0L;
        long double f1 = f;
        for (int i2 = 0; i2 < 2; i2++)
        {
            ll m = 19;
            while (m)
            {
                m = nn;
                v[i2].clear();
                while (m > 0)
                {
                    int b = (int)(r & 1);
                    v[i2].push_back(b);
                    r = (r >> 1) ^ ((__int128)b * c);
                    m -= 1 + b;
                }
            }
        }
        int e = 19;
        size_t mn = min(v[0].size(), v[1].size());
        for (size_t j = 0; j < mn; j++)
        {
            e &= (v[0][j] == v[1][j]);
        }
        if (e)
        {
            ng += sd;
            long double x = ng / na;
            long double nf = nearbyintl(x);
            f = nf;
            if (f == f1)
            {
                a = a + 1.0L / 1919.0L;
            }
            else
            {
                a = 0.0L;
            }
        }
    }
    cout << (ll)(f) << endl;
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
