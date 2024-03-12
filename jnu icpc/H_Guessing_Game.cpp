#include <bits/stdc++.h>
using namespace std;
void H_Guessing_Game()
{
    long long int n, k;
    cin >> n >> k;
    long long int sum = (n * (n + 1)) / 2;
    if (sum == k)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        H_Guessing_Game();
    return 0;
}
