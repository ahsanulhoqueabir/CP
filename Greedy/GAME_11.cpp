#include <bits/stdc++.h>
using namespace std;
#define int int
void GAME_11()
{

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    if (n < 4 or m < 4 or n + m < 11)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < 4; ++i)
        {
            sum += a[i];
            sum += b[i];
        }
        int i = 4, j = 4;
        while (i < n && j < m && (i + j) < 11)
        {
            if (a[i] > b[j])
            {
                sum += a[i];
                i++;
            }
            else
            {
                sum += b[j];
                j++;
            }
        }
        while (i < n && (i + j) < 11)
            sum += a[i], i++;
        while ((i + j) < 11 && j < m)
            sum += b[j], j++;
        cout << sum << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        GAME_11();
    return 0;
}