#include <bits/stdc++.h>
using namespace std;
void A_Make_it_White()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int b = 0, lb = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            b = i;
            break;
        }
    }
    for(int i=0;i<n;i+=1)
    {
        if(s[i]=='B') lb=i+1;
    }
    cout << lb - b << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        A_Make_it_White();
    return 0;
}