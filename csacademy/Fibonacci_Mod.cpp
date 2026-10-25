// Author : Ahsanul Hoque Abir
// Contact: contact.ahsanul@gmail.com
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

constexpr int MOD = 1'000'000'007;
constexpr ll INF = 4e18;

struct Mat
{
    ull a, b, c, d;
};

Mat mul(const Mat &x, const Mat &y, ull m)
{
    return {(x.a * y.a + x.b * y.c) % m, (x.a * y.b + x.b * y.d) % m,
            (x.c * y.a + x.d * y.c) % m, (x.c * y.b + x.d * y.d) % m};
}

void Solve()
{
    ull M, A, B;
    cin >> M >> A >> B;
    // The pair (F_K, F_{K+1}) cycles with period <= 6M, so baby-step giant-step over K.
    ll s = (ll)sqrtl((long double)6 * M) + 2;
    vector<pair<ull, ll>> baby;
    baby.reserve(s);
    ull a = 0, b = 1 % M;
    for (ll j = 0; j < s; j++)
    {
        baby.push_back({a * M + b, j});
        ull c = (a + b) % M;
        a = b;
        b = c;
    }
    sort(all(baby));
    // backward step on column (a, b): (b - a, a)
    Mat R = {1, 0, 0, 1}, base = {M - 1, 1, 1, 0};
    base.a %= M;
    for (ll e = s; e; e >>= 1)
    {
        if (e & 1) R = mul(R, base, M);
        base = mul(base, base, M);
    }
    ull x = A, y = B;
    for (ll i = 0; i <= s; i++)
    {
        auto it = lower_bound(all(baby), make_pair(x * M + y, -1LL));
        if (it != baby.end() && it->first == x * M + y)
        {
            cout << i * s + it->second << endl;
            return;
        }
        ull nx = (R.a * x + R.b * y) % M, ny = (R.c * x + R.d * y) % M;
        x = nx;
        y = ny;
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        Solve();
    }

    return 0;
}
