#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
void B_Equal_XOR()
{
    ll n, k;
    cin >> n >> k;
    map<int, int> lc, rc;
    vector<ll> v(2 * n), l, r;
    for (ll i = 0; i < 2 * n; i++)
    {
        ll x;
        cin >> x;
        v[i] = x;
        if (i < n)
        {
            lc[x]++;
            if (lc[x] == 2)
            {
                l.pb(x);
                l.pb(x);
            }
        }
        else
        {
            rc[x]++;
            if (rc[x] == 2)
            {
                r.pb(x);
                r.pb(x);
            }
        }
    }
    int ls = l.size();
    if (ls >= 2 * k)
    {
        while (ls > 2 * k)
        {
            l.pop_back();
            r.pop_back();
            ls--;
        }
    }
    else
    {
        for (auto i : lc)
        {
            if (ls == 2 * k)
                break;
            if (i.second == 1 and rc[i.first] == 1)
            {
                l.pb(i.first);
                r.pb(i.first);
                ls++;
            }
        }
    }
    for (int x : l)
        cout << x << " ";
    cout << endl;
    for (int x : r)
        cout << x << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        B_Equal_XOR();
    return 0;
}