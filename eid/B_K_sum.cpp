#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void B_K_sum()
{
    map<ll, ll> m;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), vs(n + 1);
    vs[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        // ll x;
        // cin >> x;
        // v.push_back(x);
        cin >> v[i];
        vs[i + 1] = vs[i] + v[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        m[vs[i - 1]]++;
        ans += m[vs[i] - k];
    }
    cout << ans;
}
int main()
{
    B_K_sum();
    return 0;
}