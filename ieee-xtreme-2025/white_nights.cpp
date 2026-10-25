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
    int n, q;
    if (!(cin >> n >> q))
    {
        return;
    }
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    int m = max(1, 2 * (n - 1) + 5);
    vector<int> hd(n + 1, -1);
    vector<int> to(m);
    vector<int> nx(m);
    int pt = 0;
    auto ad = [&](int u, int v)
    {
        to[pt] = v;
        nx[pt] = hd[u];
        hd[u] = pt;
        pt++;
    };
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        ad(u, v);
        ad(v, u);
    }
    const int in = 1000000000;
    vector<int> d(n + 1, in);
    queue<int> qu;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 1)
        {
            d[i] = 0;
            qu.push(i);
        }
    }
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (int e = hd[u]; e != -1; e = nx[e])
        {
            int v = to[e];
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }
    int lg = 0;
    while ((1 << lg) <= n)
    {
        lg++;
    }
    vector<int> dp(n + 1, 0);
    vector<int> vs(n + 1, 0);
    vector<int> up((lg + 1) * (n + 1), 0);
    vector<int> mn((lg + 1) * (n + 1), in);
    auto id = [&](int k, int v)
    {
        return k * (n + 1) + v;
    };
    for (int k = 0; k <= lg; k++)
    {
        up[id(k, 0)] = 0;
        mn[id(k, 0)] = in;
    }
    for (int i = 1; i <= n; i++)
    {
        mn[id(0, i)] = d[i];
    }
    queue<int> qb;
    qb.push(1);
    vs[1] = 1;
    while (!qb.empty())
    {
        int u = qb.front();
        qb.pop();
        for (int e = hd[u]; e != -1; e = nx[e])
        {
            int v = to[e];
            if (!vs[v])
            {
                vs[v] = 1;
                dp[v] = dp[u] + 1;
                up[id(0, v)] = u;
                qb.push(v);
            }
        }
    }
    for (int k = 1; k <= lg; k++)
    {
        for (int v = 1; v <= n; v++)
        {
            int p = up[id(k - 1, v)];
            up[id(k, v)] = up[id(k - 1, p)];
            int a = mn[id(k - 1, v)];
            int b = p ? mn[id(k - 1, p)] : in;
            if (b < a)
            {
                mn[id(k, v)] = b;
            }
            else
            {
                mn[id(k, v)] = a;
            }
        }
    }
    auto mv = [&](int &u, int w)
    {
        int r = in;
        for (int i = 0; i <= lg; i++)
        {
            if (w & (1 << i))
            {
                if (mn[id(i, u)] < r)
                {
                    r = mn[id(i, u)];
                }
                u = up[id(i, u)];
            }
        }
        return r;
    };
    auto fn = [&](int u, int v)
    {
        int r = in;
        if (dp[u] < dp[v])
        {
            swap(u, v);
        }
        int t = dp[u] - dp[v];
        int w = mv(u, t);
        if (w < r)
        {
            r = w;
        }
        if (u == v)
        {
            if (mn[id(0, u)] < r)
            {
                r = mn[id(0, u)];
            }
            return r;
        }
        for (int i = lg; i >= 0; i--)
        {
            if (up[id(i, u)] != up[id(i, v)])
            {
                if (mn[id(i, u)] < r)
                {
                    r = mn[id(i, u)];
                }
                if (mn[id(i, v)] < r)
                {
                    r = mn[id(i, v)];
                }
                u = up[id(i, u)];
                v = up[id(i, v)];
            }
        }
        if (mn[id(0, u)] < r)
        {
            r = mn[id(0, u)];
        }
        if (mn[id(0, v)] < r)
        {
            r = mn[id(0, v)];
        }
        u = up[id(0, u)];
        if (mn[id(0, u)] < r)
        {
            r = mn[id(0, u)];
        }
        return r;
    };
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << fn(u, v) << endl;
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
