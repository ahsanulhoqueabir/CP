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
    string s;
    int q;
    cin >> s >> q;
    vi pos[26];
    for (int i = 0; i < sz(s); i++)
        pos[s[i] - 'a'].push_back(i);
    while (q--)
    {
        string p;
        cin >> p;
        int cur = sz(s), cnt = 0;
        for (int i = sz(p) - 1; i >= 0; i--)
        {
            auto &v = pos[p[i] - 'a'];
            auto it = lower_bound(all(v), cur);
            if (it == v.begin())
                break;
            cur = *prev(it);
            cnt++;
        }
        cout << cnt << endl;
    }
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
