#include <bits/stdc++.h>
using namespace std;

bool is_valid( vector<int> &l)
{
    for (int i :l)
    {
        if (i == 0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;

    vector<int> l(k, 0);
    int b = 0;
    string ss = "";

    for (int i = 0; i < s.size(); i++)
    {
        l[s[i] - 'a'] += 1;
        if (is_valid(l))
        {
            for (int j = 0; j < k; ++j)
            {
                l[j] = 0;
            }
            b += 1;
            ss += s[i];
        }
    }

    if (b >= n) cout << "YES" << endl;
  
    else
    {
        cout << "NO" << endl;
        b = n - b;
        int z = 0;

        for (int i = 0; i < k; ++i)
        {
            if (l[i] == 0)
            {
                z = i;
                break;
            }
        }

        cout << ss;
        for (int i = 0; i < b; i += 1)
        {
            cout << char(z + 'a');
        }
        cout << "\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}