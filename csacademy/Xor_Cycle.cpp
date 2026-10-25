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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vll d(n + 1, 0);
    vector<char> vis(n + 1, 0);
    vi st = {1};
    vis[1] = 1;
    while (!st.empty())
    {
        int u = st.back();
        st.pop_back();
        for (auto &e : g[u])
            if (!vis[e.first])
            {
                vis[e.first] = 1;
                d[e.first] = d[u] ^ e.second;
                st.push_back(e.first);
            }
    }
    ll bs[62] = {};
    for (int u = 1; u <= n; u++)
        for (auto &e : g[u])
        {
            ll x = d[u] ^ d[e.first] ^ e.second;
            for (int b = 61; b >= 0 && x; b--)
            {
                if (!(x >> b & 1)) continue;
                if (!bs[b]) { bs[b] = x; break; }
                x ^= bs[b];
            }
        }
    ll ans = 0;
    for (int b = 61; b >= 0; b--)
        if ((ans ^ bs[b]) > ans) ans ^= bs[b];
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
