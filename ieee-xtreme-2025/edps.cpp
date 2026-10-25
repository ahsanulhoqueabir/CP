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
    int n;
    if (!(cin >> n))
        return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
        {
            cout << "No" << endl;
            return;
        }
        b[i] = a[i] / 2 + 1;
        if (b[i] < 1 || b[i] > n)
        {
            cout << "No" << endl;
            return;
        }
    }
    int m = 1 << n;
    vector<int> pc(m);
    for (int i = 1; i < m; i++)
        pc[i] = pc[i >> 1] + (i & 1);
    vector<int8_t> tm(m, 0), gm(m, 0);
    vector<int> rr(m, -1), fr(m, -1);
    function<bool(int)> fo;
    function<bool(int)> tr;
    fo = [&](int ms) -> bool
    {
        if (ms == 0)
            return true;
        if (gm[ms] != 0)
            return gm[ms] == 1;
        int j = __builtin_ctz(ms);
        for (int sb = ms; sb; sb = (sb - 1) & ms)
        {
            if (!((sb >> j) & 1))
                continue;
            if (!tr(sb))
                continue;
            int nm = ms ^ sb;
            if (fo(nm))
            {
                gm[ms] = 1;
                fr[ms] = sb;
                return true;
            }
        }
        gm[ms] = -1;
        return false;
    };
    tr = [&](int ms) -> bool
    {
        if (tm[ms] != 0)
            return tm[ms] == 1;
        int c = pc[ms];
        int x = ms;
        while (x)
        {
            int p = __builtin_ctz(x);
            x ^= 1 << p;
            if (b[p] != c)
                continue;
            int rm = ms ^ (1 << p);
            if (fo(rm))
            {
                tm[ms] = 1;
                rr[ms] = p;
                return true;
            }
        }
        tm[ms] = -1;
        return false;
    };
    int am = (1 << n) - 1;
    if (!fo(am))
    {
        cout << "No" << endl;
        return;
    }
    function<string(int)> bd = [&](int ms) -> string
    {
        int p = rr[ms];
        string s = "(";
        int rm = ms ^ (1 << p);
        while (rm)
        {
            int sb = fr[rm];
            s += bd(sb);
            rm ^= sb;
        }
        s += ")";
        return s;
    };
    string r;
    int ms = am;
    while (ms)
    {
        int sb = fr[ms];
        r += bd(sb);
        ms ^= sb;
    }
    cout << "Yes" << endl;
    cout << r << endl;
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
