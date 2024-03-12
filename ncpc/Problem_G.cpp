#include <bits/stdc++.h>
using namespace std;
void Problem_G(int t)
{
    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            cnt++;
            // cnt2++;
        }
        else
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] == b[j])
                {
                    cnt2 += (j - i);
                    i = j;
                    break;
                    // return;
                }
            }
        }
    }
    // cout << cnt << " " << cnt2 << endl;
    if (cnt == 0)
        cout << "Case " << t << ": " << n << endl;
    else if (cnt == n)
        cout << "Case " << t << ": " << 0 << endl;
    else
        cout << "Case " << t << ": " << (cnt2 - cnt + 1) << endl;
}
int main()
{
    int t;
    cin >> t;
    int tmp = t;
    while (t--)
    {
        int x = tmp - t;
        Problem_G(x);
    }
    return 0;
}