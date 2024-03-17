#include <bits/stdc++.h>
using namespace std;
long long get(long long x, long long y, long long z)
{
    long long sum = 0;
    sum += x * 100 + y * 10 + z;
    sum += y * 100 + z * 10 + x;
    sum += z * 100 + x * 10 + y;
    return sum;
}
void E_Cyclic_Sum()
{
    long long n;
    cin >> n;
    long long sum = 0;
    long long x = n % 10;
    n /= 10;
    long long y = n % 10;
    n /= 10;
    long long z = n % 10;
    cout << get(x, y, z);
}
int main()
{
    E_Cyclic_Sum();
    return 0;
}