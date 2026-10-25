#include <bits/stdc++.h>
using namespace std;
void isPalindrome(string &s, int &l)
{
    // string ss = s;
    // int l = s.size();
    for (int i = 0; i < (l / 2); i++)
    {
        if (s[i] != s[l - i - 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
const int N = 1e5 + 2;
char tree[4 * N];

void build(char s, int start, int end)
{
    if (start == end)
    {
        tree[start] = s;
        // return;
    }
    int mid = (start + end) / 2;
    build(s, start, mid);
    build(s, mid + 1, end);
    tree[end] = tree[start];
}
void T_Easy_Peasy_Palindrome_Squeezy()
{
    int n, m;
    int k;
    int l, r;
    char ch;
    cin >> n >> m;
    string s;

    // cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    build(s[0], 0, n - 1);
    for (int i = 0; i < 4 * n; i++)
    {
        cout << tree[i] << " ";
    }
}
while (m--)
{
    int c;
    cin >> c;
    if (c == 1)
    {
        cin >> k >> ch;
        s[k - 1] = ch;
    }
    if (c == 2)
    {

        cin >> l >> r;
        l--;
        r--;
        int x = r - l + 1;
        string ss = s.substr(l, r - l + 1);
        isPalindrome(ss, x);
    }
}
}
int main()
{
    T_Easy_Peasy_Palindrome_Squeezy();
    return 0;
}

/*
aybabtu
abcdefg










*/