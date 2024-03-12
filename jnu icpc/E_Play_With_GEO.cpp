#include <bits/stdc++.h>
using namespace std;
void E_Play_With_GEO()
{
    float q;
    cin >> q;
    float p = (abs(90 - q) / 3);
    float r = abs(2 * p + q);
    cout << fixed << setprecision(6);
    if (r >= p)
    {
        cout
            << r << " " << p << endl;
    }
    else
    {
        cout
            << p << " " << r << endl;
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        E_Play_With_GEO();
    return 0;
}