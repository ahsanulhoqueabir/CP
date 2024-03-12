#include <bits/stdc++.h>
using namespace std;
void C_Rudolf_and_the_Ugly_String()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = "map", s2 = "pie";
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s1[0])
        {
            int j = 1;
            while (j < 3 and s[i + j] == s1[j])
            {
                j++;
            }
            if (j == 3)
                cnt++;
        }
        if (s[i] == s2[0])
        {

            int j = 1;
            while (j < 3 and s[i + j] == s2[j])
            {
                j++;
            }
            if (j == 3)
                cnt++;

            if (s[i - 1] == 'a' and s[i - 2] == 'm' and s[i + 1] == 'i' and s[i + 2] == 'e')
            {
                cnt--;
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        C_Rudolf_and_the_Ugly_String();
    return 0;
}