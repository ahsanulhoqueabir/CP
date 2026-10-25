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

int val(char c)
{
    return isdigit(c) ? c - '0' : c - 'A' + 10;
}

void Solve()
{
    int n;
    cin >> n;
    vector<array<int, 12>> a(n);
    for (auto &x : a)
    {
        string s;
        cin >> s;
        int k = 0;
        for (char c : s)
            if (c != '-')
                x[k++] = val(c);
    }
    ll ans = 0;
    vector<ull> keys(n);
    for (int p = 0; p < 12; p++)
    {
        for (int i = 0; i < n; i++)
        {
            ull h = 0;
            for (int j = 0; j < 12; j++)
                h = h * 36 + (j == p ? 0 : a[i][j]);
            keys[i] = h;
        }
        sort(all(keys));
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && keys[j] == keys[i])
                j++;
            ans += (ll)(j - i) * (j - i - 1) / 2;
            i = j;
        }
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
        Solve();
    }

    return 0;
}
