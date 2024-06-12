#include <bits/stdc++.h>
using namespace std;
void A_Stickogon()
{
    int n, p;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        m[p]++;
    }
    int ans = 0;
    for (auto x : m)
    {
        ans += (x.second / 3);
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        A_Stickogon();
    return 0;
}