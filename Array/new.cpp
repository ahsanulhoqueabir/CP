#include <bits/stdc++.h>
using namespace std;
void C_MEX_Game_1()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (s.size() == n)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        
        for (int i = 0; i < n; i++)
        {
            if (*s.begin() == 0 )
            {
                cout << 1 << endl;
                return;
            }
            if (s.count(i) == 0)
            {
                cout << i << endl;
                return;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        C_MEX_Game_1();
    return 0;
}
