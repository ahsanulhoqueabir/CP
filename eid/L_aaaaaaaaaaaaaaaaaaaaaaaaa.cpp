#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    // int n = s.length();
    // for (int i = 0; i < n / 2; i++)
    // {
    //     if (s[i] != s[n - i - 1])
    //         return false;
    // }
    // return true;
    string ss = s;
    reverse(ss.begin(), ss.end());
    return s == ss;
}
void L_aaaaaaaaaaaaaaaaaaaaaaaaa()
{
    string s;
    cin >> s;

    int l = s.length(), cnt = 0, cntt = 0;
    for (auto &i : s)
    {
        if (i == 'a')
            cnt++;
        else
            break;
    }

    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] == 'a')
            cntt++;
        else

            break;
    }
    if (cnt == l)
    {
        cout << "Yes\n";
        return;
    }
    if (cnt > cntt)
    {
        cout << "No\n";
        return;
    }
    for (int i = cnt; i < (l - cntt); i++)
    {
        if (s[i] != s[cnt + l - cntt - i - 1])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes"
         << "\n";
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        L_aaaaaaaaaaaaaaaaaaaaaaaaa();
    return 0;
}