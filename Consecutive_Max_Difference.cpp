// Author : Ahsanul Hoque Abir
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

// Bucket (pigeonhole) approach: the max gap is >= ceil((mx-mn)/(n-1)),
// so only inter-bucket gaps matter.
ll maxGap(const vll &a)
{
    int n = sz(a);
    if (n < 2)
        return 0;
    ll mn = *min_element(all(a)), mx = *max_element(all(a));
    if (mn == mx)
        return 0;
    ll w = max(1LL, (mx - mn) / (n - 1));
    int b = (mx - mn) / w + 1;
    vll lo(b, LLONG_MAX), hi(b, LLONG_MIN);
    for (ll x : a)
    {
        int i = (x - mn) / w;
        lo[i] = min(lo[i], x);
        hi[i] = max(hi[i], x);
    }
    ll best = 0, prev = mn;
    for (int i = 0; i < b; i++)
    {
        if (lo[i] == LLONG_MAX)
            continue;
        best = max(best, lo[i] - prev);
        prev = hi[i];
    }
    return best;
}

void Solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (auto &x : a)
        cin >> x;
    cout << maxGap(a) << endl;
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
