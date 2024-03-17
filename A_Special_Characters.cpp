#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void A_Special_Characters()
{
    ll n;
    cin >> n;
    if (n % 2 == 1)
        cout << "NO"
             << "\n";
    else
    {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n / 2; i++)
            cout << "AAB";
        cout << "\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        A_Special_Characters();
    return 0;
}