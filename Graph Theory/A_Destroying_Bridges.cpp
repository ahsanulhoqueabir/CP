#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void A_Destroying_Bridges()
{
    ll n, k;
    cin >> n >> k;
    if (k >= (n - 1))
        cout << 1 << endl;
    else
        cout << n << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        A_Destroying_Bridges();
    return 0;
}