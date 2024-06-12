#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 5;
long long sum[N];
// #define int long long int
void solve()
{
    long long int n, k, x;
    cin >> n >> k >> x;
    long long int p = (k * (k + 1)) / 2;
    long long int q = ((n * (n + 1) / 2)) - ((n - k) * (n - k + 1) / 2);
    if (p > x or q < x)
        cout << "NO";
    else
        cout << "YES";
    cout << "\n";
}
int main()
{

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
