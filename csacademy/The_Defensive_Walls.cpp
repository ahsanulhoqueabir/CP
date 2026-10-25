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

int n;
vector<array<int, 4>> w; // x1,y1,x2,y2 with (x1,y1) the low/left end
vector<char> hor;

// frame f: rotation so that heading f becomes "east"
void tr(int f, int x, int y, int &a, int &b)
{
    switch (f)
    {
    case 0: a = x; b = y; break;
    case 1: a = y; b = -x; break;
    case 2: a = -x; b = -y; break;
    default: a = -y; b = x;
    }
}
void inv(int f, int a, int b, int &x, int &y)
{
    switch (f)
    {
    case 0: x = a; y = b; break;
    case 1: x = -b; y = a; break;
    case 2: x = -a; y = -b; break;
    default: x = b; y = -a;
    }
}

struct Frame
{
    vi ys;
    int P = 1;
    vector<vector<pii>> t;
    void build(int f)
    {
        vector<array<int, 3>> ws; // x', lo, hi
        vi id;
        for (int i = 0; i < n; i++)
        {
            bool perp = (f % 2 == 0) ? !hor[i] : (bool)hor[i];
            if (!perp) continue;
            int ax, ay, bx, by;
            tr(f, w[i][0], w[i][1], ax, ay);
            tr(f, w[i][2], w[i][3], bx, by);
            ws.push_back({ax, min(ay, by), max(ay, by)});
            id.push_back(i);
            ys.push_back(min(ay, by));
            ys.push_back(max(ay, by));
        }
        sort(all(ys));
        ys.erase(unique(all(ys)), ys.end());
        int m = sz(ys);
        while (P < max(1, m - 1)) P <<= 1;
        t.assign(2 * P, {});
        for (int k = 0; k < sz(ws); k++)
        {
            int r1 = lower_bound(all(ys), ws[k][1]) - ys.begin();
            int r2 = lower_bound(all(ys), ws[k][2]) - ys.begin();
            int l = r1 + P, r = r2 + P;
            while (l < r)
            {
                if (l & 1) t[l++].push_back({ws[k][0], id[k]});
                if (r & 1) t[--r].push_back({ws[k][0], id[k]});
                l >>= 1; r >>= 1;
            }
        }
        for (auto &v : t) sort(all(v));
    }
    // first wall with x' > px covering y'-eps (mode 0) or y'+eps (mode 1)
    pii query(int px, int py, int mode) const
    {
        int m = sz(ys);
        if (m < 2) return {INT_MAX, -1};
        int c = mode == 0 ? (int)(lower_bound(all(ys), py) - ys.begin()) - 1
                          : (int)(upper_bound(all(ys), py) - ys.begin()) - 1;
        if (c < 0 || c >= m - 1) return {INT_MAX, -1};
        pii best = {INT_MAX, -1};
        for (int i = c + P; i >= 1; i >>= 1)
        {
            auto it = upper_bound(all(t[i]), pii(px, INT_MAX));
            if (it != t[i].end() && it->first < best.first) best = *it;
        }
        return best;
    }
};
Frame fr[4];

vi par;
int fnd(int x) { return par[x] == x ? x : par[x] = fnd(par[x]); }
void unite(int a, int b) { par[fnd(a)] = fnd(b); }

void Solve()
{
    cin >> n;
    w.resize(n);
    hor.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a + b > c + d) { swap(a, c); swap(b, d); }
        w[i] = {a, b, c, d};
        hor[i] = (b == d);
    }
    par.resize(n);
    iota(all(par), 0);

    // components via sweep
    {
        vector<array<int, 3>> ev; // x, type, id
        for (int i = 0; i < n; i++)
        {
            if (hor[i])
            {
                ev.push_back({w[i][0], 0, i});
                ev.push_back({w[i][2], 2, i});
            }
            else ev.push_back({w[i][0], 1, i});
        }
        sort(all(ev));
        set<pii> act, U;
        auto fix = [&](set<pii>::iterator a)
        {
            auto s = next(a);
            if (s != act.end() && fnd(a->second) != fnd(s->second)) U.insert(*a);
            else U.erase(*a);
        };
        for (auto &e : ev)
        {
            int id = e[2];
            if (e[1] == 0)
            {
                auto it = act.insert({w[id][1], id}).first;
                if (it != act.begin()) fix(prev(it));
                fix(it);
            }
            else if (e[1] == 2)
            {
                auto it = act.find({w[id][1], id});
                U.erase(*it);
                bool hasPrev = it != act.begin();
                pii pv;
                if (hasPrev) pv = *prev(it);
                act.erase(it);
                if (hasPrev) fix(act.find(pv));
            }
            else
            {
                int y1 = w[id][1], y2 = w[id][3];
                auto it = act.lower_bound({y1, -1});
                if (it == act.end() || it->first > y2) continue;
                unite(id, it->second);
                auto k = U.lower_bound(*it);
                while (k != U.end() && k->first <= y2)
                {
                    auto s = next(act.find(*k));
                    if (s == act.end() || s->first > y2) break;
                    unite(k->second, s->second);
                    k = U.erase(k);
                }
            }
        }
    }

    for (int f = 0; f < 4; f++) fr[f].build(f);

    // seed per component: lowest, then leftmost, horizontal preferred
    vector<array<int, 4>> best(n, {INT_MAX, INT_MAX, 2, -1});
    for (int i = 0; i < n; i++)
    {
        int r = fnd(i);
        array<int, 4> key = {w[i][1], w[i][0], hor[i] ? 0 : 1, i};
        if (key < best[r]) best[r] = key;
    }
    vi comps;
    for (int i = 0; i < n; i++)
        if (fnd(i) == i) comps.push_back(i);
    sort(all(comps), [&](int a, int b) { return best[a] < best[b]; });

    vector<vector<pii>> topEdges(n); // heading-west edges (free side up) on wall
    vector<ull> area2(n, 0);
    for (int c : comps)
    {
        auto &bk = best[c];
        int sx = bk[1], sy = bk[0], sw = bk[3];
        int sh = bk[2] == 0 ? 0 : 1;
        int x = sx, y = sy, h = sh, cw = sw;
        ull s = 0;
        long long guard = 0;
        do
        {
            int A, B, Bx, By;
            tr(h, w[cw][0], w[cw][1], A, B);
            tr(h, w[cw][2], w[cw][3], Bx, By);
            int limit = max(A, Bx);
            int px, py;
            tr(h, x, y, px, py);
            int nx, ny, nh, nw;
            pii r = fr[h].query(px, py, 0);
            if (r.first <= limit)
            {
                inv(h, r.first, py, nx, ny);
                nh = (h + 3) % 4;
                nw = r.second;
            }
            else
            {
                inv(h, limit, py, nx, ny);
                pii l = fr[h].query(limit - 1, py, 1);
                if (l.first == limit)
                {
                    nh = (h + 1) % 4;
                    nw = l.second;
                }
                else
                {
                    nh = (h + 2) % 4;
                    nw = cw;
                }
            }
            if (h == 2) topEdges[cw].push_back({min(x, nx), max(x, nx)});
            s += (ull)(ll)x * (ull)(ll)ny - (ull)(ll)nx * (ull)(ll)y;
            x = nx; y = ny; h = nh; cw = nw;
            if (++guard > 40000000LL) break;
        } while (!(x == sx && y == sy && h == sh && cw == sw));
        area2[c] = s;
    }
    for (auto &v : topEdges) sort(all(v));

    vector<char> top(n, 0);
    ull ans2 = 0;
    for (int c : comps)
    {
        int sx = best[c][1], sy = best[c][0];
        pii r = fr[3].query(-sy, sx, 1);
        if (r.second < 0) top[c] = 1;
        else
        {
            int wl = r.second, d = fnd(wl);
            bool on = false;
            auto &v = topEdges[wl];
            // interval with lo <= sx and sx+1 <= hi
            auto it = upper_bound(all(v), pii(sx, INT_MAX));
            if (it != v.begin())
            {
                --it;
                on = it->first <= sx && sx + 1 <= it->second;
            }
            top[c] = top[d] && on;
        }
        if (top[c]) ans2 += area2[c];
    }
    cout << (ll)(ans2 / 2) << endl;
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
