#include <bits/stdc++.h>
using namespace std;
void C_Simple_Multiplication()
{
    int a, ans;
    cin >> a;
    ans = a + (a * a) + (a * a * a);
    cout << ans << endl;
}
int main()
{
    C_Simple_Multiplication();
    return 0;
}