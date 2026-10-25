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

// xor of 0..x
ll f(ll x)
{
    if (x < 0) return 0;
    switch (x & 3)
    {
    case 0: return x;
    case 1: return 1;
    case 2: return x + 1;
    default: return 0;
    }
}

ll rangeXor(ll a, ll b) { return f(b) ^ f(a - 1); }

void Solve()
{
    ll l, h, n, d1, d2;
    cin >> l >> h >> n >> d1 >> d2;
    ll i1 = d1 - n, i2 = d2 - n;
    ll r1 = i1 / l, c1 = i1 % l, r2 = i2 / l, c2 = i2 % l;
    ll cl = min(c1, c2), cr = max(c1, c2);
    ll ans = rangeXor(n, n + l * h - 1);
    for (ll r = r1; r <= r2; r++)
        ans ^= rangeXor(n + r * l + cl, n + r * l + cr);
    cout << ans << endl;
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
        Solve();
    }

    return 0;
}
