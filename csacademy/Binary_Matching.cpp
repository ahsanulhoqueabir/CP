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
constexpr int INFI = 1e9;

void Solve()
{
    string T, P;
    cin >> T >> P;
    int n = sz(T), m = sz(P);
    if (m > n) { cout << "0 0" << endl; return; }
    vi A(n + 1, 0), po(m + 1, 0);
    for (int i = 0; i < n; i++) A[i + 1] = A[i] + (T[i] == '1');
    for (int i = 0; i < m; i++) po[i + 1] = po[i] + (P[i] == '1');
    int c1 = A[n], c0 = n - c1;
    vi f(m + 1, 0);
    for (int i = 1, k = 0; i < m; i++)
    {
        while (k && P[i] != P[k]) k = f[k];
        if (P[i] == P[k]) k++;
        f[i + 1] = k;
    }
    int p = m - f[m];
    vi periods;
    for (int b = f[m]; b > 0; b = f[b])
    {
        int d = m - b;
        if (d == p || d % p != 0) periods.push_back(d);
    }
    int K = (n - m) / p + 1;
    int L = m + 1;
    size_t layer = (size_t)(c1 + 1) * (K + 1);
    vi G(layer * L, INFI), H(layer * L, INFI);
    auto id = [&](int x, int j, int t) { return (size_t)(x % L) * layer + (size_t)j * (K + 1) + t; };
    G[id(0, 0, 0)] = 0;
    int ones = po[m], zeros = m - ones;
    int bestT = 0, bestC = 0;
    for (int x = 0; x <= n; x++)
    {
        for (int j = max(0, x - c0); j <= min(c1, x); j++)
        {
            int z = x - j;
            for (int t = 0; t <= K; t++)
            {
                int cur = G[id(x, j, t)];
                if (cur >= INFI) continue;
                if (x == n) continue;
                if (j < c1)
                {
                    int &r = G[id(x + 1, j + 1, t)];
                    r = min(r, cur + abs(A[x + 1] - (j + 1)));
                }
                if (z < c0)
                {
                    int &r = G[id(x + 1, j, t)];
                    r = min(r, cur + abs(A[x + 1] - j));
                }
                if (t < K && x + m <= n && j + ones <= c1 && z + zeros <= c0)
                {
                    int c = cur;
                    for (int i = 1; i <= m; i++) c += abs(A[x + i] - (j + po[i]));
                    int &r = G[id(x + m, j + ones, t + 1)];
                    r = min(r, c);
                    int &s = H[id(x + m, j + ones, t + 1)];
                    s = min(s, c);
                }
                int h = H[id(x, j, t)];
                if (h < INFI && t < K)
                    for (int d : periods)
                    {
                        if (x + d > n) continue;
                        int o = po[m] - po[m - d];
                        if (j + o > c1 || z + d - o > c0) continue;
                        int c = h, base = po[m - d];
                        for (int i = 1; i <= d; i++) c += abs(A[x + i] - (j + po[m - d + i] - base));
                        int &r = G[id(x + d, j + o, t + 1)];
                        r = min(r, c);
                        int &s = H[id(x + d, j + o, t + 1)];
                        s = min(s, c);
                    }
            }
        }
        if (x == n)
        {
            for (int t = K; t >= 0; t--)
                if (G[id(n, c1, t)] < INFI) { bestT = t; bestC = G[id(n, c1, t)]; break; }
        }
        for (int j = 0; j <= c1; j++)
            for (int t = 0; t <= K; t++)
                G[id(x, j, t)] = H[id(x, j, t)] = INFI;
    }
    cout << bestT << " " << bestC << endl;
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
