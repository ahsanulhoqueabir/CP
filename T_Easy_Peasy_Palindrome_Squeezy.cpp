#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    while (m--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int k;
            char ch;
            cin >> k >> ch;
            s[k - 1] = ch;
        }
        else if (c == 2)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int x = r - l + 1;
            if (isPalindrome(s, l, r))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
