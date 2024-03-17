#include <bits/stdc++.h>
using namespace std;
void C_Count_Trees()
{
    int n, q;
    string s[n][n];
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cin >> s[i][j];
        }
    }
    // Count the number of trees in each row and store it in a vector
    vector<int> cnt(n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cnt[i] = cnt[i - 1] + (s[i][j] == '1');
        }
    }
    cout << "Number of Trees: " << cnt[n - 1] << endl;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << cnt[r] - cnt[l] + (s[l][l] == '1') << endl;
    }
}
int main()
{
    C_Count_Trees();
    return 0;
}