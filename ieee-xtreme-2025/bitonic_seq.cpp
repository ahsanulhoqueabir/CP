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
    const long long MOD = 1000000007LL;
    int m;
    if (!(cin >> m))
        return;

    vector<long long> fib(m + 4);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= m + 3; ++i)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    for (int n = 1; n <= m; ++n)
    {
        long long ans = (fib[n + 3] - (n + 1)) % MOD;
        if (ans < 0)
            ans += MOD;
        cout << ans;
        if (n < m)
            cout << ' ';
    }
    cout << endl; 
}

int main()
{

    fraction();
    optimize();

    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case : " << i << " " << Solve();
        Solve();
    }

    return 0;
}
