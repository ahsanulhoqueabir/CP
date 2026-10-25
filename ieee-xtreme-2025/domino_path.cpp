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

vector<pair<int, int>> vp(21);
int mp[8][8];
vector<int> sv;
bool rd = false;

void Pre()
{
    if (rd)
        return;
    rd = true;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            mp[i][j] = -1;
    int p = 0;
    for (int i = 1; i <= 7; i++)
        for (int j = i + 1; j <= 7; j++)
        {
            mp[i][j] = p;
            mp[j][i] = p;
            vp[p] = {i - 1, j - 1};
            p++;
        }
    int tt = 1 << 21;
    sv.assign(tt, 0);
    int ad[7];
    int dg[7];
    for (int m = 1; m < tt; m++)
    {
        for (int i = 0; i < 7; i++)
        {
            ad[i] = 0;
            dg[i] = 0;
        }
        for (int k = 0; k < 21; k++)
        {
            if (m & (1 << k))
            {
                int u = vp[k].first;
                int v = vp[k].second;
                dg[u]++;
                dg[v]++;
                ad[u] |= 1 << v;
                ad[v] |= 1 << u;
            }
        }
        int st = -1;
        for (int i = 0; i < 7; i++)
        {
            if (dg[i] > 0)
            {
                st = i;
                break;
            }
        }
        if (st == -1)
            continue;
        int q[7];
        int hd = 0;
        int tl = 0;
        q[tl++] = st;
        int vs = 1 << st;
        while (hd < tl)
        {
            int u = q[hd++];
            int nb = ad[u];
            while (nb)
            {
                int v = __builtin_ctz(nb);
                nb ^= 1 << v;
                if (!(vs & (1 << v)))
                {
                    vs |= 1 << v;
                    q[tl++] = v;
                }
            }
        }
        bool ck = true;
        int od = 0;
        for (int i = 0; i < 7; i++)
        {
            if (dg[i] > 0 && !(vs & (1 << i)))
                ck = false;
            if (dg[i] & 1)
                od++;
        }
        if (ck && (od == 0 || od == 2))
            sv[m] = 1;
    }
    for (int b = 0; b < 21; b++)
        for (int m = 0; m < tt; m++)
            if (m & (1 << b))
                sv[m] += sv[m ^ (1 << b)];
}

void Solve()
{
    Pre();
    int m;
    cin >> m;
    int ms = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        int id = mp[x][y];
        if (id >= 0)
            ms |= 1 << id;
    }
    cout << sv[ms] << endl;
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
