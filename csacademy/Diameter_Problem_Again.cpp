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
constexpr int NEG = -1'000'000'000;
constexpr int LG = 20;

struct Node
{
    int a, la, b;
};

const Node EMPTY = {NEG, -3, NEG};

inline void ins(Node &r, int val, int lab)
{
    if (lab == r.la)
        r.a = max(r.a, val);
    else if (val > r.a)
    {
        r.b = r.a;
        r.a = val;
        r.la = lab;
    }
    else
        r.b = max(r.b, val);
}

inline Node mergeN(const Node &x, const Node &y)
{
    Node r = x;
    ins(r, y.a, y.la);
    r.b = max(r.b, y.b);
    return r;
}

struct List
{
    vector<Node> t;
    vi pos;
    int len = 0, cap = 0;

    void grow()
    {
        int nc = max(1, cap * 2);
        vector<Node> nt(2 * nc, EMPTY);
        for (int i = 0; i < len; i++)
            nt[nc + i] = t[cap + i];
        for (int i = nc - 1; i >= 1; i--)
            nt[i] = mergeN(nt[2 * i], nt[2 * i + 1]);
        t.swap(nt);
        pos.resize(nc);
        cap = nc;
    }

    void push(int p, int val, int lab)
    {
        if (len == cap)
            grow();
        pos[len] = p;
        int i = cap + len;
        t[i] = {val, lab, NEG};
        for (i >>= 1; i >= 1; i >>= 1)
            t[i] = mergeN(t[2 * i], t[2 * i + 1]);
        len++;
    }

    Node query(int l, int r) // [l, r)
    {
        Node res = EMPTY;
        for (l += cap, r += cap; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = mergeN(res, t[l++]);
            if (r & 1)
                res = mergeN(res, t[--r]);
        }
        return res;
    }
};

int n;
vi cen[LG], dst[LG], lev;
vector<List> lists;

void Solve()
{
    cin >> n;
    vi eu(n - 1), ev(n - 1), ew(n - 1), deg(n + 2, 0);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> eu[i] >> ev[i] >> ew[i];
        deg[eu[i]]++;
        deg[ev[i]]++;
    }
    vi st(n + 2, 0);
    for (int i = 1; i <= n; i++)
        st[i + 1] = st[i] + deg[i];
    vi adjV(2 * (n - 1)), adjW(2 * (n - 1)), fill(st.begin(), st.end());
    for (int i = 0; i < n - 1; i++)
    {
        adjV[fill[eu[i]]] = ev[i];
        adjW[fill[eu[i]]++] = ew[i];
        adjV[fill[ev[i]]] = eu[i];
        adjW[fill[ev[i]]++] = ew[i];
    }

    for (int j = 0; j < LG; j++)
    {
        cen[j].assign(n + 1, 0);
        dst[j].assign(n + 1, 0);
    }
    lev.assign(n + 1, 0);
    vector<char> removed(n + 1, 0);
    vi par(n + 1), sub(n + 1), order, dd(n + 1);
    vector<pii> work = {{1, 0}};
    while (!work.empty())
    {
        int root = work.back().first, level = work.back().second;
        work.pop_back();
        order.clear();
        order.push_back(root);
        par[root] = 0;
        for (int i = 0; i < sz(order); i++)
        {
            int u = order[i];
            sub[u] = 1;
            for (int e = st[u]; e < st[u + 1]; e++)
            {
                int v = adjV[e];
                if (v != par[u] && !removed[v])
                {
                    par[v] = u;
                    order.push_back(v);
                }
            }
        }
        for (int i = sz(order) - 1; i > 0; i--)
            sub[par[order[i]]] += sub[order[i]];
        int tot = sz(order), c = root;
        while (true)
        {
            int nx = -1;
            for (int e = st[c]; e < st[c + 1]; e++)
            {
                int v = adjV[e];
                if (v != par[c] && !removed[v] && sub[v] * 2 > tot)
                {
                    nx = v;
                    break;
                }
            }
            if (nx < 0)
                break;
            c = nx;
        }
        order.clear();
        order.push_back(c);
        par[c] = 0;
        dd[c] = 0;
        for (int i = 0; i < sz(order); i++)
        {
            int u = order[i];
            cen[level][u] = c;
            dst[level][u] = dd[u];
            for (int e = st[u]; e < st[u + 1]; e++)
            {
                int v = adjV[e];
                if (v != par[u] && !removed[v])
                {
                    par[v] = u;
                    dd[v] = dd[u] + adjW[e];
                    order.push_back(v);
                }
            }
        }
        lev[c] = level;
        removed[c] = 1;
        for (int e = st[c]; e < st[c + 1]; e++)
            if (!removed[adjV[e]])
                work.push_back({adjV[e], level + 1});
    }

    lists.assign(n + 1, List());
    vi stk;
    int m;
    cin >> m;
    ll last = 0;
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;
            int v = (int)((x ^ llabs(last)) % n) + 1;
            int p = sz(stk);
            for (int j = 0; j <= lev[v]; j++)
            {
                int lab = (lev[v] > j) ? cen[j + 1][v] : -1;
                lists[cen[j][v]].push(p, dst[j][v], lab);
            }
            stk.push_back(v);
        }
        else if (type == 2)
        {
            int v = stk.back();
            stk.pop_back();
            for (int j = 0; j <= lev[v]; j++)
                lists[cen[j][v]].len--;
        }
        else
        {
            ll l, r, x;
            cin >> l >> r >> x;
            ll a = sz(stk), ab = llabs(last);
            int v = (int)((x ^ ab) % n) + 1;
            l = ((l ^ ab) % a) + 1;
            r = ((r ^ ab) % a) + 1;
            if (l > r)
                swap(l, r);
            int l0 = (int)l - 1, r0 = (int)r - 1;
            ll best = -INF;
            for (int j = 0; j <= lev[v]; j++)
            {
                List &L = lists[cen[j][v]];
                int lo = lower_bound(L.pos.begin(), L.pos.begin() + L.len, l0) - L.pos.begin();
                int hi = upper_bound(L.pos.begin(), L.pos.begin() + L.len, r0) - L.pos.begin();
                if (lo >= hi)
                    continue;
                Node res = L.query(lo, hi);
                int xl = (lev[v] > j) ? cen[j + 1][v] : -2;
                int bv = (res.la != xl) ? res.a : res.b;
                if (bv > NEG / 2)
                    best = max(best, (ll)dst[j][v] + bv);
            }
            last = best;
            cout << best << endl;
        }
    }
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
