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

int n, K;
string s;
set<string> sq;

bool dfs()
{
    if (sz(s) == n) return true;
    for (char c : {'y', 'Y'})
    {
        s += c;
        vector<string> added;
        int len = sz(s);
        for (int l = 1; 2 * l <= len; l++)
        {
            if (s.compare(len - 2 * l, l, s, len - l, l) == 0)
            {
                string w = s.substr(len - 2 * l);
                if (sq.insert(w).second) added.push_back(w);
            }
        }
        if (sz(sq) <= K && dfs()) return true;
        for (auto &w : added) sq.erase(w);
        s.pop_back();
    }
    return false;
}

void Solve()
{
    cin >> n;
    for (K = 0;; K++)
    {
        s.clear();
        sq.clear();
        if (dfs()) break;
    }
    cout << s << endl;
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
