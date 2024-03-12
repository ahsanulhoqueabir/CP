#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, n;
    cin >> x >> n;
    int q = x / n;
    int f= sqrt(x);
    set<int> st;
    for (int i = 1; i <= f; i++)
    {
        if (x % i == 0)
        {
            st.insert(i);
            st.insert(x / i);
        }
    }
    auto it = st.lower_bound(q);
    if (*it > q)
    {
        it--;
    }
    cout << *it << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}