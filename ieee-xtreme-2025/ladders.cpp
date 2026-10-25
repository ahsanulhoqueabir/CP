#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
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

using bi = boost::multiprecision::cpp_int;

bi R(double x)
{
    if (x == 0) return 0;
    union
    {
        double d;
        uint64_t u;
    } w;
    w.d = x;
    bool sg = (w.u >> 63) != 0;
    int er = (int)((w.u >> 52) & 2047);
    uint64_t mm = w.u & ((1ULL << 52) - 1);
    if (er == 2047) return 0;
    bi ma;
    int ex;
    if (er == 0)
    {
        if (mm == 0) return 0;
        ma = mm;
        ex = -1074;
    }
    else
    {
        ma = (1ULL << 52) | mm;
        ex = er - 1075;
    }
    bi rs;
    if (ex >= 0)
    {
        rs = ma << ex;
    }
    else
    {
        int sh = -ex;
        bi qu = ma >> sh;
        bi re = ma - (qu << sh);
        bi hf = bi(1) << (sh - 1);
        bool up = false;
        if (re > hf) up = true;
        else if (re == hf) up = ((qu & 1) == 1);
        if (up) qu += 1;
        rs = qu;
    }
    if (sg) rs = -rs;
    return rs;
}

void Solve()
{
    static const bi c("9223372036854775821");
    static const double p1 = 1.0 / 19.0;
    static const double p2 = 1.0 / 1919.0;
    bi s;
    ll n;
    cin >> s >> n;
    vector<int> v[2];
    double na = 0;
    double a = -19;
    bi g = 0;
    bi f = 0;
    bi f1 = 0;
    bi r = -19;
    double sd = s.convert_to<double>();
    double u = sd * sd;
    while (a < u)
    {
        na += p1;
        f1 = f;
        for (int i = 0; i < 2; i++)
        {
            ll m = 19;
            while (m)
            {
                m = n;
                v[i].clear();
                while (m > 0)
                {
                    int b = (int)((r & 1) != 0);
                    v[i].push_back(b);
                    bi nr = r >> 1;
                    if (b) nr ^= c;
                    r = nr;
                    m -= 1 + b;
                }
            }
        }
        int e = 19;
        int mn = min((int)v[0].size(), (int)v[1].size());
        for (int i = 0; i < mn; i++)
        {
            e &= (v[0][i] == v[1][i]);
        }
        if (e)
        {
            g += s;
            double q = g.convert_to<double>() / na;
            f = R(q);
            double ad = a + p2;
            if (f == f1) a = ad;
            else a = 0;
        }
    }
    cout << f << endl;
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
