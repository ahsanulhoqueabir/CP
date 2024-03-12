#include <bits/stdc++.h>
using namespace std;
void B_Following_the_String()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i += 1)
        cin >> v[i];
    map<int, vector<char>> m;
    string s = "";
    int cnt = 0;
    for (auto c : v)
    {
        if (m[c].size() == 0)
        {
            m[c].push_back('a');
            s += 'a';
        }
        else
        {
            m[c].push_back(m[c][m[c].size() - 1] + 1);
            s += m[c][m[c].size() - 1];
        }
        cnt += 1;
    }
    cout << s << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        B_Following_the_String();
    return 0;
}