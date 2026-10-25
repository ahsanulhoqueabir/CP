
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(6);            \
    cout.setf(ios::fixed, ios::floatfield);

const int K = 1000000007;

ll f(ll a)
{
    static vector<int> c = {1, 2, 4, 20, 40, 80, 200, 400, 800};
    static vector<int> d(1, 1);
    int k = (int)(a / 25);
    while ((int)d.size() <= k)
    {
        ll s = 0;
        int i = d.size();
        for (int x : c)
        {
            if (i >= x)
            {
                s += d[i - x];
                if (s >= K)
                    s -= K;
            }
        }
    d.push_back((int)s);
    }
    return d[k];
}

void Solve()
{
    ll n, m, a;
    cin >> n >> m >> a;
    ll t = n * 5300;
    ll w = f(t);
    ll md = llabs(w - m);
    ll ad = llabs(w - a);
    if (md < ad)
        cout << "Mikel" << endl;
    else if (ad < md)
        cout << "Andrew" << endl;
    else if (md == 0 && ad == 0)
        cout << "TIE" << endl;
    else
        cout << "NONE" << endl;
}

int main()
{
    fraction();
    optimize();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    return 0;
}
