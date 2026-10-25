#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        ll N;
        cin >> N;

        if (N & 1ULL)
        {
            cout << -1 << endl;
            continue;
        }

        if ((N & (N - 1ULL)) == 0ULL)
        {
            cout << -1 << endl;
            continue;
        }

        ll half = N >> 1;

        if (half & (half << 1))
        {
            ll C = half;
            ll doubled = half << 1;
            ll A = doubled & half;
            ll xorPart = doubled ^ half;
            ll B = A ^ xorPart;
            cout << A << ' ' << B << ' ' << C << endl;
        }
        else
        {
            ll C = N & -N; // lowest set bit
            ll A = half;
            ll xorPart = N - C;
            ll B = A ^ xorPart;
            cout << A << ' ' << B << ' ' << C << endl;
        }
    }

    return 0;
}