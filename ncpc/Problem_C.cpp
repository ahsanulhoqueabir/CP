#include <bits/stdc++.h>
using namespace std;
#define ll long long
// const int N=1e5+7;
// int ct[N];
// const long long M=1e9+10;
long long c = 1;
// string a;
// long long l=1;
// long long sum[N];
// long long sum1=0;
// long asci[128];
// long long m[N];
bool sortbyCond(const pair<int, int> &a,
                const pair<int, int> &b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}
void solve()
{
    ll n, a, p, ctp = 0, ctu = 0, ctd = n, ct = 0;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for (ll i = 1; i < n - 1; i++)
        if (v[i - 1] < v[i] && v[i + 1] < v[i])
        {
            p = i;
            ctp++;
        }
    for (ll i = 0; i < n - 1; i++)
        if (v[i] < v[i + 1])
        {
            ctu = i;
            break;
        }
    for (ll i = p; i < n - 1; i++)
        if (v[i] < v[i + 1])
        {
            ctd = i;
            break;
        }
    // cout<<p<<" "<<ctp<<" "<<ctu<<" "<<ctd<<" ";
    for (ll i = ctu; i <= ctd; i++)
        if (v[i] % ctp == 0)
            ct++;
    if (ctp > 0)
        cout << "Case " << c << ": " << ct;
    else
        cout << "Case " << c << ": " << -1;
    c++;
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}