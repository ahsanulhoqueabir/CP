#include <bits/stdc++.h>
using namespace std;
void J_Lecixo_Lexigo_Whatever()
{

    int n;
    cin >> n;
    vector<int> v(n), ans;

    for (auto &i : v)
    {
        cin >> i;
    }
    int mx = v[n - 1];
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] > v[i + 1])
        {
            mx = v[i];
            break;
        }
    }
    for (auto &i : v)
    {
        if (i != mx)
        {
            ans.push_back(i);
        }
    }
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}
int main()
{
    J_Lecixo_Lexigo_Whatever();
    return 0;
}