#include <bits/stdc++.h>
using namespace std;
void String_Rotation()
{
    int f[128] = {0}, ff[128] = {0};
    string s, ss;
    cin >> s >> ss;
    for (auto &i : s)
    {
        f[i - 'a']++;
    }
    for (auto &i : ss)
    {
        ff[i - 'a']++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (f[i] != ff[i])
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
int main()
{
    String_Rotation();
    return 0;
}