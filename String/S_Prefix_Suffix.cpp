#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> Createlps(string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void S_Prefix_Suffix()
{
    vector<int> v;
    string s;
    cin >> s;
    vector<int> lps = Createlps(s);
    vector<int> ans;
    int j = lps[s.size() - 1];
    while (j > 0)
    {
        ans.push_back(j);
        j = lps[j - 1];
    }
    sort(ans.begin(), ans.end());
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}
int main()
{
    S_Prefix_Suffix();
    return 0;
}