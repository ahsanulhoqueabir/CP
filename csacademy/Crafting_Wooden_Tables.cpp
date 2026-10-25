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
    ll C, N, P, W;
    cin >> C >> N >> P >> W;
    // T tables feasible iff leftover wood packs into the N-T remaining slots
    ll lo = 0, hi = W / C;
    while (lo < hi)
    {
        ll T = lo + (hi - lo + 1) / 2;
        ll rem = W - T * C;
        ll piles = (rem + P - 1) / P;
        if (piles + T <= N)
            lo = T;
        else
            hi = T - 1;
    }
    cout << lo << endl;
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
