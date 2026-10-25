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
    int n, m;
    if (!(cin >> n >> m))
    {
        return;
    }
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    function<int(int, int)> f = [&](int x, int y)
    {
        int &r = dp[x][y];
        if (r != -1)
        {
            return r;
        }
        r = 1;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] > a[x][y])
            {
                r = max(r, 1 + f(nx, ny));
            }
        }
        return r;
    };
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, f(i, j));
        }
    }
    cout << ans << endl;
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
