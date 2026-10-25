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

int n, m, S, T;
vector<vector<pii>> g;

void dijkstra(int src, vll &d, vi &par, vi &order)
{
    d.assign(n + 1, INF);
    par.assign(n + 1, 0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    d[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        ll du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (du != d[u])
            continue;
        order.push_back(u);
        for (auto &pr : g[u])
        {
            int v = pr.first, w = pr.second;
            if (du + w < d[v])
            {
                d[v] = du + w;
                par[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

void Solve()
{
    cin >> n >> m >> S >> T;
    g.assign(n + 1, {});
    vector<array<int, 3>> E(m);
    for (auto &e : E)
    {
        cin >> e[0] >> e[1] >> e[2];
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
    }
    vll dS, dT;
    vi pS, pT, oS, oT;
    dijkstra(S, dS, pS, oS);
    dijkstra(T, dT, pT, oT);
    if (dS[T] >= INF)
    {
        cout << -1 << endl;
        return;
    }
    vi path;
    for (int v = T; v != S; v = pS[v])
        path.push_back(v);
    path.push_back(S);
    reverse(all(path));
    int k = sz(path) - 1;
    vi idx(n + 1, -1);
    for (int i = 0; i <= k; i++)
        idx[path[i]] = i;
    for (int i = 0; i < k; i++)
        pT[path[i]] = path[i + 1];
    vi a(n + 1, -1), b(n + 1, -1);
    for (int u : oS)
        a[u] = idx[u] >= 0 ? idx[u] : a[pS[u]];
    for (int u : oT)
        b[u] = idx[u] >= 0 ? idx[u] : b[pT[u]];

    vector<tuple<ll, int, int>> cand;
    auto add = [&](int u, int w, int len)
    {
        if (dS[u] >= INF || dT[w] >= INF)
            return;
        int l = a[u] + 1, r = b[w] - 1;
        if (l <= r)
            cand.push_back({dS[u] + len + dT[w], l, r});
    };
    for (auto &e : E)
    {
        add(e[0], e[1], e[2]);
        add(e[1], e[0], e[2]);
    }
    sort(all(cand));
    vll val(k + 1, INF);
    vi nxt(k + 2);
    iota(all(nxt), 0);
    function<int(int)> find = [&](int x)
    {
        while (nxt[x] != x)
            x = nxt[x] = nxt[nxt[x]];
        return x;
    };
    for (auto &c : cand)
    {
        ll v = get<0>(c);
        int l = get<1>(c), r = get<2>(c);
        for (int i = find(l); i <= r; i = find(i))
        {
            val[i] = v;
            nxt[i] = i + 1;
        }
    }
    ll best = -1;
    int ans = -1;
    for (int i = 1; i < k; i++)
        if (val[i] < INF && val[i] > best)
            best = val[i], ans = path[i];
    for (int v = 1; v <= n; v++)
        if (idx[v] < 0 && dS[T] > best)
            best = dS[T], ans = v;
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
        Solve();
    }

    return 0;
}
