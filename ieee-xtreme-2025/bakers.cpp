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

void Solve()
{
    int q;
    cin >> q;
    int n = 1000000;
    vector<int> fl(n + 1, 1);
    fl[0] = 0;
    fl[1] = 0;
    vector<int> pr;
    for (int i = 2; i <= n; i++)
    {
        if (fl[i])
        {
            pr.push_back(i);
            ll v = (ll)i * (ll)i;
            if (v <= n)
            {
                for (int j = (int)v; j <= n; j += i)
                {
                    fl[j] = 0;
                }
            }
        }
    }
    int m = (int)pr.size();
    vector<vector<int>> oc(m);
    for (int i = 0; i < m; i++)
    {
        int p = pr[i];
        for (int j = i; j < m; j++)
        {
            ll v = (ll)p * (ll)pr[j];
            if (v > n)
            {
                break;
            }
            oc[i].push_back((int)v);
            if (i != j)
            {
                oc[j].push_back((int)v);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        auto &w = oc[i];
        sort(w.begin(), w.end());
    }
    struct Q
    {
        int l;
        int r;
        int i;
    };
    vector<Q> qq(q);
    for (int i = 0; i < q; i++)
    {
        int l;
        int r;
        cin >> l >> r;
        qq[i].l = l;
        qq[i].r = r;
        qq[i].i = i;
    }
    int b = 700;
    vector<int> hv;
    vector<pair<int, int>> ev;
    for (int i = 0; i < m; i++)
    {
        auto &w = oc[i];
        int s = (int)w.size();
        if (s > b)
        {
            hv.push_back(i);
        }
        else if (s > 1)
        {
            for (int j = 0; j < s; j++)
            {
                for (int k = j + 1; k < s; k++)
                {
                    ev.push_back({w[k], w[j]});
                }
            }
        }
    }
    sort(ev.begin(), ev.end());
    vector<Q> rq = qq;
    sort(rq.begin(), rq.end(), [&](const Q &x, const Q &y)
    {
        if (x.r != y.r)
        {
            return x.r < y.r;
        }
        return x.l < y.l;
    });
    vector<ll> fw(n + 2);
    auto up = [&](int x, ll y)
    {
        while (x <= n)
        {
            fw[x] += y;
            x += x & -x;
        }
    };
    auto gt = [&](int x)
    {
        ll s = 0;
        while (x > 0)
        {
            s += fw[x];
            x -= x & -x;
        }
        return s;
    };
    vector<ll> an(q);
    int e = 0;
    int es = (int)ev.size();
    for (auto &w : rq)
    {
        while (e < es && ev[e].first <= w.r)
        {
            up(ev[e].second, 1);
            e++;
        }
        ll t = (ll)e;
        an[w.i] += t - gt(w.l - 1);
    }
    for (int idx : hv)
    {
        auto &w = oc[idx];
        for (auto &x : qq)
        {
            int c = (int)(upper_bound(w.begin(), w.end(), x.r) - lower_bound(w.begin(), w.end(), x.l));
            an[x.i] += (ll)c * (ll)(c - 1) / 2;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << an[i] << endl;
    }
}

int main()
{

    fraction();
    optimize();

    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    return 0;
}
