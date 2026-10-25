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
    vector<vi> nx(2, vi(n));
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < n; i++)
        {
            cin >> nx[k][i];
            nx[k][i]--;
        }
    const char ch[2] = {'W', 'B'};
    vi cur(n);
    iota(all(cur), 0);
    string ans;
    while (sz(cur) > 1)
    {
        int u = cur[0], v = cur[1];
        vi par(n * n, -1), pc(n * n, 0);
        queue<int> q;
        par[u * n + v] = u * n + v;
        q.push(u * n + v);
        int found = -1;
        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            int a = s / n, b = s % n;
            if (a == b)
            {
                found = s;
                break;
            }
            for (int k = 0; k < 2; k++)
            {
                int t = nx[k][a] * n + nx[k][b];
                if (par[t] == -1)
                {
                    par[t] = s;
                    pc[t] = k;
                    q.push(t);
                }
            }
        }
        if (found < 0)
        {
            cout << "impossible" << endl;
            return;
        }
        string w;
        for (int s = found; s != u * n + v; s = par[s])
            w += ch[pc[s]];
        reverse(all(w));
        for (char c : w)
        {
            int k = c == 'B';
            for (int &x : cur)
                x = nx[k][x];
            sort(all(cur));
            cur.erase(unique(all(cur)), cur.end());
        }
        ans += w;
    }
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
