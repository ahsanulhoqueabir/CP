#include <bits/stdc++.h>
using namespace std;

bool isValidString(string str)
{
    bool oneFound = false;
    for (char c : str)
    {
        if (c == '1')
        {
            if (oneFound)
            {
                return false;
            }
            oneFound = true;
        }
        else if (c != '0')
        {
            return false;
        }
    }
    return oneFound;
}
void ALIEN_OR()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        bool valid = isValidString(str);
        if (valid)
        {
            s.insert(str);
        }
    }
    if (s.size() == m)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        ALIEN_OR();
    return 0;
}