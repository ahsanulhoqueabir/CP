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

void Solve()
{
    int n;
    cin >> n;
    map<int, pair<int, ll>> m; // left -> (right, soldiers)
    for (int i = 1; i <= n; i++)
    {
        ll s;
        cin >> s;
        m[i] = {i, s};
    }
    int d;
    cin >> d;
    ll ans = 0;
    while (d--)
    {
        int l, r;
        ll v;
        cin >> l >> r >> v;
        auto it = m.upper_bound(l);
        if (it != m.begin())
        {
            auto p = prev(it);
            if (p->second.first >= l)
                it = p;
        }
        int nl = l, nr = r;
        ll sum = 0;
        while (it != m.end() && it->first <= r)
        {
            nl = min(nl, it->first);
            nr = max(nr, it->second.first);
            sum += it->second.second;
            it = m.erase(it);
        }
        ll x = min(v, sum);
        ans += x;
        m[nl] = {nr, sum - x};
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        Solve();
    }

    return 0;
}
