#include <bits/stdc++.h>
using namespace std;
void S_Prefix_Suffix()
{
    vector<int> v;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < (n / 2) + 1; i++)
    {
        if (s.substr(0, i) == s.substr(n - i, n))
        {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    for (auto &i : v)
    {
        cout << i << " ";
    }
}
int main()
{
    S_Prefix_Suffix();
    return 0;
}