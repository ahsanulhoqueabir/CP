#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;

    string s="a";
    char ch = 'a';
    for (int i = 1; i < k; i++)
    {
        ch++;
        s+=ch;
    }

    // cout << s << endl;
    for(int i=0;i<n;i+=1)
    {
        cout << s;
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}