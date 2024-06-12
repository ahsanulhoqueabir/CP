#include <bits/stdc++.h>
using namespace std;
void A_Prefix_Suffix_Sum_1()
{
    int n, x;
    cin >> n;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pref[i + 1] = pref[i] + x;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r + 1] - pref[l] << endl;
    }
}
int main()
{
    A_Prefix_Suffix_Sum_1();
    return 0;
}