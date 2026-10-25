#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void A_Hapi_Hapi_New_yar()
{
    ll n;
    cin >> n;
    string s;
    while (n > 0)
    {
        s.push_back('0' + (n % 2));
        n /= 2;
    }
    reverse(s.begin(), s.end());
    for (auto &i : s)
    {
        if (i == '1')
            cout << '2';

        else
            cout << '0';
    }
}
int main()
{
    A_Hapi_Hapi_New_yar();
    return 0;
}