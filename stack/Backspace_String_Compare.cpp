#include <bits/stdc++.h>
using namespace std;
void Backspace_String_Compare()
{
    string s, t;
    cin >> s >> t;
    stack<char> st1, st2;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '#')
            st1.push(s[i]);

        if (s[i] == '#' and !st1.empty())
            st1.pop();
    }
    for (auto &i : t) // you can iterate this ways also. though it have more time complexity
    {
        if (i != '#')
            st2.push(i);
        if (i == '#' and !st2.empty())
            st2.pop();
    }
    if (st1 == st2)
        cout << "true";

    else
        cout << "false";
}
int main()
{
    Backspace_String_Compare();
    return 0;
}