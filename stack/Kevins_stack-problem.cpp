#include <bits/stdc++.h>
string kevinStackProblem(string &s)
{
    string ss;
    while (!s.empty())
    {
        ss.push_back(s.back());
        s.pop_back();
    }
    return ss;
}
