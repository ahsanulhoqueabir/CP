#include <bits/stdc++.h>
using namespace std;
void E_Prefix_Suffix_Sum_5()
{
    ifstream cin("div7.in");
    ofstream cout("div7.out");
    int n, x;
    cin >> n;
    vector<long long> pref(n + 1, 0);
    vector<int> start(7, INT_MAX), end(7, 0);
    start[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        pref[i] = (pref[i - 1] + x) % 7;
        start[pref[i]] = min(start[pref[i]], i);
        end[pref[i]] = i;
    }
    for (int i = 0; i < 7; i++)
    {
        if (start[i] != INT_MAX)
        {
            ans = max(ans, end[i] - start[i]);
        }
    }
    cout << ans << endl;
}
int main()
{
    E_Prefix_Suffix_Sum_5();
    return 0;
}