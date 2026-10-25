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
    if (!(cin >> n)) return;
    string a;
    cin >> a;
    int m;
    cin >> m;
    string b;
    cin >> b;
    ll mt;
    ll ms;
    ll gp;
    cin >> mt >> ms >> gp;
    ll nf = (ll)-4e18;
    vector<ll> d0(m + 1, nf), d1(m + 1, nf), x0(m + 1, nf), x1(m + 1, nf), y0(m + 1, nf), y1(m + 1, nf);
    vector<int> p0(m + 1, 0), p1(m + 1, 0), q0(m + 1, 0), q1(m + 1, 0);
    d0[0] = 0;
    for (int j = 1; j <= m; j++)
    {
        y0[j] = gp * (ll)j * j;
        q0[j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        ll v1 = max(d0[0], y0[0]);
        ll s1 = v1 > nf / 2 ? v1 + gp : nf;
        ll e1 = x0[0] > nf / 2 ? x0[0] + gp * (2LL * p0[0] + 1) : nf;
        if (e1 >= s1)
        {
            x1[0] = e1;
            p1[0] = e1 > nf / 2 ? p0[0] + 1 : 0;
        }
        else
        {
            x1[0] = s1;
            p1[0] = s1 > nf / 2 ? 1 : 0;
        }
        d1[0] = nf;
        y1[0] = nf;
        q1[0] = 0;
        for (int j = 1; j <= m; j++)
        {
            ll v2 = max({d0[j - 1], x0[j - 1], y0[j - 1]});
            if (v2 > nf / 2)
            {
                ll sc = (a[i - 1] == b[j - 1]) ? mt : ms;
                d1[j] = v2 + sc;
            }
            else d1[j] = nf;
            ll v3 = max(d0[j], y0[j]);
            ll s2 = v3 > nf / 2 ? v3 + gp : nf;
            ll e2 = x0[j] > nf / 2 ? x0[j] + gp * (2LL * p0[j] + 1) : nf;
            if (e2 >= s2)
            {
                x1[j] = e2;
                p1[j] = e2 > nf / 2 ? p0[j] + 1 : 0;
            }
            else
            {
                x1[j] = s2;
                p1[j] = s2 > nf / 2 ? 1 : 0;
            }
            ll v4 = max(d1[j - 1], x1[j - 1]);
            ll s3 = v4 > nf / 2 ? v4 + gp : nf;
            ll e3 = y1[j - 1] > nf / 2 ? y1[j - 1] + gp * (2LL * q1[j - 1] + 1) : nf;
            if (e3 >= s3)
            {
                y1[j] = e3;
                q1[j] = e3 > nf / 2 ? q1[j - 1] + 1 : 0;
            }
            else
            {
                y1[j] = s3;
                q1[j] = s3 > nf / 2 ? 1 : 0;
            }
        }
        swap(d0, d1);
        swap(x0, x1);
        swap(y0, y1);
        swap(p0, p1);
        swap(q0, q1);
    }
    ll rs = max({d0[m], x0[m], y0[m]});
    cout << rs << endl;
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
