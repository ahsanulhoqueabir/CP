#include <bits/stdc++.h>
using namespace std;
void C_Arrow_Path()
{
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    int dp[2][n];

    dp[0][n - 1] = 0;
    dp[1][n - 1] = 1;
    dp[1][n - 2] = 0;
    if (s[1][n - 2] == '>')
    {
        dp[0][n - 2] = 1;
    }
    else
    {
        dp[0][n - 2] = 0;
    }
    for (int i = n - 3; i >= 0; i--)
    {
        dp[0][i] = 0;
        if (s[0][i + 1] == '>' && dp[0][i + 2] == 1)
        {
            dp[0][i] = 1;
        }
        if (s[1][i] == '>' && dp[1][i + 1] == 1)
        {
            dp[0][i] = 1;
        }
        dp[1][i] = 0;
        if (s[1][i + 1] == '>' && dp[1][i + 2] == 1)
        {
            dp[1][i] = 1;
        }
        if (s[0][i] == '>' && dp[0][i + 1] == 1)
        {
            dp[1][i] = 1;
        }
    }

    if (dp[0][0] == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        C_Arrow_Path();
    return 0;
}