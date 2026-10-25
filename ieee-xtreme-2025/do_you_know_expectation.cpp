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

struct B
{
    unsigned long long l;
    unsigned long long h;
};

int tp(const B &x)
{
    if (x.h) return 64 + 63 - __builtin_clzll(x.h);
    if (x.l) return 63 - __builtin_clzll(x.l);
    return -1;
}

unsigned long long gt(const B &x, int p)
{
    if (p < 64) return (x.l >> p) & 1ULL;
    return (x.h >> (p - 64)) & 1ULL;
}

void st(B &x, int p)
{
    if (p < 64) x.l |= (1ULL << p);
    else x.h |= (1ULL << (p - 64));
}

B ad(B a, B b)
{
    B c;
    c.l = a.l + b.l;
    c.h = a.h + b.h + (c.l < a.l);
    return c;
}

void ad(B &a, unsigned long long v)
{
    unsigned long long o = a.l;
    a.l += v;
    if (a.l < o) ++a.h;
}

B sh(B a, int k)
{
    if (k == 0) return a;
    B c;
    c.l = a.l << k;
    unsigned long long carry = a.l >> (64 - k);
    c.h = (a.h << k) | carry;
    return c;
}

pair<B, unsigned long long> dv(const B &a, unsigned int w)
{
    B q{0, 0};
    unsigned long long r = 0;
    int t = tp(a);
    if (t < 0) return {q, 0};
    for (int i = t; i >= 0; --i) {
        r = (r << 1) | gt(a, i);
        if (r >= w) {
            r -= w;
            st(q, i);
        }
    }
    return {q, r};
}

string gs(B a)
{
    if (a.h == 0 && a.l == 0) return "0";
    string s;
    while (a.h || a.l) {
        auto d = dv(a, 10);
        a = d.first;
        s.push_back(char('0' + d.second));
    }
    reverse(s.begin(), s.end());
    return s;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    array<int, 10> b{};
    for (int i = 0; i < n; ++i) {
        int y = a[i];
        for (int j = 9; j >= 0; --j) {
            if (((y >> j) & 1) == 0) continue;
            if (!b[j]) {
                b[j] = y;
                break;
            }
            y ^= b[j];
        }
    }
    vector<int> v;
    for (int i = 0; i < 10; ++i) if (b[i]) {
        int y = b[i];
        for (int j = i - 1; j >= 0; --j) if (b[j] && ((y >> j) & 1)) y ^= b[j];
        v.push_back(y);
    }
    int r = (int)v.size();
    B s{0, 0};
    int t = 1 << r;
    for (int m = 0; m < t; ++m) {
        int x = 0;
        for (int j = 0; j < r; ++j) if ((m >> j) & 1) x ^= v[j];
        unsigned long long y = 1;
        for (int j = 0; j < k; ++j) y *= (unsigned long long)x;
        s = ad(s, B{y, 0});
    }
    B u = ad(ad(sh(s, 6), sh(s, 5)), sh(s, 2));
    int w = 1 << r;
    ad(u, (unsigned long long)(w - 1));
    B c = dv(u, w).first;
    auto d = dv(c, 100);
    B p = d.first;
    unsigned long long q = d.second;
    string s1 = gs(p);
    string s2 = to_string((int)q);
    if ((int)s2.size() < 2) s2 = string(2 - (int)s2.size(), '0') + s2;
    cout << s1 << '.' << s2 << '\n';
}

int main()
{

    fraction();
    optimize();

    int t = 1;
   // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case : " << i << " " << Solve();
        Solve();
    }

    return 0;
}
