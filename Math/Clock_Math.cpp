#include <bits/stdc++.h>
using namespace std;
void Clock_Math()
{
    float a, b, s;
    cin >> a >> b;
    // s = abs(11 * (a + 1) - 60 * b) / 2;
    s = abs(30 * a - 5.5 * b);

    cout << setprecision(4) << fixed;
    if (s < 180)
    {
        cout << s;
    }
    else
    {
        cout << 360 - s;
    }
}
int main()
{
    Clock_Math();
    return 0;
}