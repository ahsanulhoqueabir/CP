#include <bits/stdc++.h>
using namespace std;
void C_MEX_Game_1()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> val(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        val[v[i]]++;
    }
    int ans = 0;
    bool flag = 1;
    for (int i = 0; i <= n; i++)
    {
        if (val[i] == 0)
        {
            ans = i;
            break;
        }
        else if (val[i] == 1)
        {
            if (flag)
            {
                flag = 0;
            }
            else
            {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        C_MEX_Game_1();
    return 0;
}
