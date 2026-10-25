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
    struct D
    {
        set<string> ag;
        set<string> ip;
        set<string> ss;
        ll pc = 0;
        vector<ll> pv;
    };

    auto tr = [&](string s) -> string
    {
        int i = 0;
        int j = (int)s.size() - 1;
        while (i <= j && isspace((unsigned char)s[i]))
            i++;
        while (j >= i && isspace((unsigned char)s[j]))
            j--;
        if (i > j)
            return "";
        return s.substr(i, j - i + 1);
    };

    auto sp = [&](string s) -> vector<string>
    {
        vector<string> v;
        string t;
        for (int i = 0; i <= (int)s.size(); i++)
        {
            if (i == (int)s.size() || s[i] == ',')
            {
                v.push_back(tr(t));
                t.clear();
            }
            else
            {
                t.push_back(s[i]);
            }
        }
        return v;
    };

    auto tk = [&](string &s, int &p) -> string
    {
        int n = (int)s.size();
        while (p < n && s[p] == ' ')
            p++;
        if (p >= n)
            return "";
        if (s[p] == '"')
        {
            int q = p + 1;
            while (q < n && s[q] != '"')
                q++;
            string t = s.substr(p + 1, q - p - 1);
            p = q < n ? q + 1 : n;
            return t;
        }
        if (s[p] == '[')
        {
            int q = p + 1;
            while (q < n && s[q] != ']')
                q++;
            string t = s.substr(p + 1, q - p - 1);
            p = q < n ? q + 1 : n;
            return t;
        }
        int q = p;
        while (q < n && s[q] != ' ')
            q++;
        string t = s.substr(p, q - p);
        p = q;
        return t;
    };

    auto ad = [&](map<string, map<string, ll>> &rs, const string &a, const string &b, ll v)
    {
        auto it = rs.find(a);
        if (it == rs.end())
        {
            map<string, ll> t;
            t[b] = v;
            rs.insert({a, t});
            return;
        }
        auto jt = it->second.find(b);
        if (jt == it->second.end() || v > jt->second)
            it->second[b] = v;
    };

    string r;
    while (getline(cin, r))
    {
        string t = tr(r);
        if (t.size())
        {
            r = t;
            break;
        }
    }
    if (!cin || !tr(r).size())
    {
        cout << "N/A" << endl;
        return;
    }
    vector<string> rv = sp(r);
    map<string, ll> th;
    for (string &w : rv)
    {
        size_t po = w.find('=');
        if (po == string::npos)
            continue;
        string k = tr(w.substr(0, po));
        string v = tr(w.substr(po + 1));
        if (!k.size() || !v.size())
            continue;
        th[k] = stoll(v);
    }
    string h;
    while (getline(cin, h))
    {
        string t = tr(h);
        if (t.size())
        {
            h = t;
            break;
        }
    }
    if (!cin || !tr(h).size())
    {
        cout << "N/A" << endl;
        return;
    }
    vector<string> hd = sp(h);
    int m = (int)hd.size();
    map<string, int> fm;
    for (int i = 0; i < m; i++)
    {
        hd[i] = tr(hd[i]);
        fm[hd[i]] = i;
    }
    if (!fm.count("Id") || !fm.count("Client IP") || !fm.count("Date") || !fm.count("Request") || !fm.count("HTTP Status") || !fm.count("User Agent") || !fm.count("Session Cookie"))
    {
        cout << "N/A" << endl;
        return;
    }
    int zi = fm["Id"];
    int zp = fm["Client IP"];
    int zd = fm["Date"];
    int zr = fm["Request"];
    int zs = fm["HTTP Status"];
    int zu = fm["User Agent"];
    int zc = fm["Session Cookie"];

    map<string, map<string, D>> dt;
    string l;
    while (getline(cin, l))
    {
        string tl = tr(l);
        if (!tl.size())
            continue;
        int p = 0;
        vector<string> fv;
        fv.reserve(m);
        for (int i = 0; i < m; i++)
        {
            string t = tk(l, p);
            fv.push_back(t);
        }
        string id = fv[zi];
        if (!id.size() || id == "-")
            continue;
        string st = fv[zs];
        if (st != "200")
            continue;
        string da = fv[zd];
        size_t co = da.find(':');
        if (co == string::npos)
            continue;
        string dy = da.substr(0, co);
        D &d = dt[id][dy];
        string ua = fv[zu];
        if (ua.size() && ua != "-")
            d.ag.insert(ua);
        string cp = fv[zp];
        if (cp.size() && cp != "-")
            d.ip.insert(cp);
        string sc = fv[zc];
        if (sc.size() && sc != "-")
            d.ss.insert(sc);
        string rq = fv[zr];
        ll pn = -1;
        size_t p1 = rq.find("/document/");
        if (p1 != string::npos)
        {
            size_t p2 = rq.find(".pdf", p1);
            if (p2 != string::npos)
            {
                size_t b = p1 + 10;
                if (p2 > b)
                {
                    string nm = rq.substr(b, p2 - b);
                    bool dg = true;
                    for (char c : nm)
                    {
                        if (!isdigit((unsigned char)c))
                        {
                            dg = false;
                            break;
                        }
                    }
                    if (dg)
                        pn = stoll(nm);
                }
            }
        }
        if (pn != -1)
        {
            d.pc++;
            d.pv.push_back(pn);
        }
    }

    ll ta = -1, ti = -1, tp = -1, ts = -1, tc = -1;
    auto ia = th.find("agent");
    if (ia != th.end())
        ta = ia->second;
    auto ii = th.find("ip");
    if (ii != th.end())
        ti = ii->second;
    auto pf = th.find("pdf");
    if (pf != th.end())
        tp = pf->second;
    auto is = th.find("session");
    if (is != th.end())
        ts = is->second;
    auto ic = th.find("crawl");
    if (ic != th.end())
        tc = ic->second;

    map<string, map<string, ll>> rs;
    for (auto &a : dt)
    {
        for (auto &b : a.second)
        {
            D &d = b.second;
            if (ta != -1)
            {
                ll v = (ll)d.ag.size();
                if (v >= ta)
                    ad(rs, a.first, "agent", v);
            }
            if (ti != -1)
            {
                ll v = (ll)d.ip.size();
                if (v >= ti)
                    ad(rs, a.first, "ip", v);
            }
            if (tp != -1)
            {
                ll v = d.pc;
                if (v >= tp)
                    ad(rs, a.first, "pdf", v);
            }
            if (ts != -1)
            {
                ll v = (ll)d.ss.size();
                if (v >= ts)
                    ad(rs, a.first, "session", v);
            }
            if (tc != -1)
            {
                ll br = 0;
                ll cr = 0;
                ll la = 0;
                for (ll x : d.pv)
                {
                    if (cr && x == la + 1)
                        cr++;
                    else
                        cr = 1;
                    la = x;
                    if (cr > br)
                        br = cr;
                }
                if (br >= tc)
                    ad(rs, a.first, "crawl", br);
            }
        }
    }
    if (!rs.size())
    {
        cout << "N/A" << endl;
        return;
    }
    for (auto &a : rs)
    {
        for (auto &b : a.second)
            cout << a.first << " " << b.first << "=" << b.second << endl;
    }
}

int main()
{

    fraction();
    optimize();

    int t = 1;
   // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case : " << i << " " << Solve();
        Solve();
    }

    return 0;
}
