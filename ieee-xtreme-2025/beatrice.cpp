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

using ul = unsigned long long;

ul hx(ul x)
{
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    x ^= (x >> 31);
    return x;
}

void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> p(n + 1, -1);
    vector<int> o;
    o.reserve(n);
    vector<int> st;
    st.reserve(n);
    st.push_back(1);
    p[1] = 0;
    while (!st.empty())
    {
        int u = st.back();
        st.pop_back();
        o.push_back(u);
        for (int v : g[u])
        {
            if (v == p[u])
            {
                continue;
            }
            p[v] = u;
            st.push_back(v);
        }
    }
    vector<ul> dh(n + 1);
    vector<int> di(n + 1);
    unordered_map<ul, int> um;
    um.reserve(n * 2);
    um.max_load_factor(0.7);
    vector<ul> vb;
    int id = 0;
    for (int i = (int)o.size() - 1; i >= 0; i--)
    {
        int u = o[i];
        vb.clear();
        for (int v : g[u])
        {
            if (v == p[u])
            {
                continue;
            }
            vb.push_back(dh[v]);
        }
        sort(vb.begin(), vb.end());
        ul h = hx(vb.size());
        for (ul x : vb)
        {
            h = hx(h ^ x);
        }
        h = hx(h + 0x517cc1b727220a95ULL);
        dh[u] = h;
        auto it = um.find(h);
        if (it == um.end())
        {
            id++;
            um[h] = id;
            di[u] = id;
        }
        else
        {
            di[u] = it->second;
        }
    }
    vector<vector<int>> cn;
    cn.reserve(n);
    vector<int> cs;
    cs.reserve(n);
    queue<int> qu;
    cn.push_back(vector<int>());
    cn[0].push_back(1);
    cs.push_back(1);
    qu.push(0);
    while (!qu.empty())
    {
        int ci = qu.front();
        qu.pop();
        auto &vc = cn[ci];
        unordered_map<int, int> mm;
        mm.reserve(vc.size() * 2 + 1);
        mm.max_load_factor(0.7);
        for (int u : vc)
        {
            for (int v : g[u])
            {
                if (v == p[u])
                {
                    continue;
                }
                int kk = di[v];
                int ni;
                auto jt = mm.find(kk);
                if (jt == mm.end())
                {
                    ni = cn.size();
                    mm[kk] = ni;
                    cn.push_back(vector<int>());
                    cs.push_back(0);
                    qu.push(ni);
                }
                else
                {
                    ni = jt->second;
                }
                cn[ni].push_back(v);
                cs[ni]++;
            }
        }
    }
    int an = 0;
    for (int i = 0; i < (int)cs.size(); i++)
    {
        if (cs[i] == 1)
        {
            an++;
        }
    }
    cout << an << endl;
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
