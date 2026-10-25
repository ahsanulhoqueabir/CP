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
    int n, k;
    cin >> n >> k;
    vi cnt(n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int pre = 0, ans = 0;
    for (int v = 0; v <= n; v++)
    {
        pre += cnt[v];
        if (cnt[v] == 0 || pre < (v + 1) * k)
            break;
        ans = v + 1;
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
