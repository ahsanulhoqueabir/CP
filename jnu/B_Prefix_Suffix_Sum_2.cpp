#include <bits/stdc++.h>
using namespace std;
void B_Prefix_Suffix_Sum_2()
{

    int n, q, x;
    cin >> n >> q;
    vector<int> b1(n + 1, 0), b2(n + 1, 0), b3(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b1[i + 1] = b1[i] + (x == 1 ? 1 : 0);
        b2[i + 1] = b2[i] + (x == 2 ? 1 : 0);
        b3[i + 1] = b3[i] + (x == 3 ? 1 : 0);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int b = b1[r] - b1[l - 1];
        int bb = b2[r] - b2[l - 1];
        int bbb = b3[r] - b3[l - 1];
        cout << b << " " << bb << " " << bbb << endl;
    }
    // for (int i = 0; i < n + 1; i += 1)
    // {
    //     cout << b1[i] << " ";
    // }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    // B_Prefix_Suffix_Sum_2();
    int n, q, x;
    cin >> n >> q;
    vector<int> b1(n + 1, 0), b2(n + 1, 0), b3(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b1[i + 1] = b1[i] + (x == 1 ? 1 : 0);
        b2[i + 1] = b2[i] + (x == 2 ? 1 : 0);
        b3[i + 1] = b3[i] + (x == 3 ? 1 : 0);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int b = b1[r] - b1[l - 1];
        int bb = b2[r] - b2[l - 1];
        int bbb = b3[r] - b3[l - 1];
        cout << b << " " << bb << " " << bbb << endl;
    }
    return 0;
}