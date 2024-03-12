#include <bits/stdc++.h>
#define AHSAN                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

void I_Integer_Division()
{
    int n, q;
    cin >> n >> q;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    while (q--)
    {
        long long int m;
        cin >> m;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != 0)
            {

                v[i] = ceil(v[i] / m);
            }
            else
            {
                cnt++;
            }
        }
        if (cnt == v.size())
        {
            // cout << m << endl;
            break;
            // return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    AHSAN
    int t = 1;
    // cin >> t;
    while (t--)
        I_Integer_Division();
    return 0;
}