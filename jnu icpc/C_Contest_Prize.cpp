/*--------------------------------------------------------*
 *                                                         *
 *      **       *     *   ** ****       **      *     **  *
 *     *  *      *     *   *            *  *     *    ***  *
 *    ******     * * * *   *** ***     ******    *   *  *  *
 *   *      *    *     *         *    *      *   ***    *  *
 *  *        *   *     *   *** ***   *        *  **     *  *
 *_________________________________________________________*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define in(z) cin >> z;
#define inn(z) \
    ll z;      \
    cin >> z;
#define sin(z) \
    string z;  \
    cin >> z;
#define vin(v, n)    \
    vector<ll> v(n); \
    loop(i, 0, n) in(v[i]);
#define out(x) cout << x;
#define outs(x) cout << x << " ";
#define outn(x) cout << x << "\n";
#define py cout << "YES" \
                << "\n";
#define pn cout << "NO" \
                << "\n";
#define nl cout << "\n";
#define vp vector<pair<ll, ll>>
#define dsc greater<ll>()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end());
#define dsrt(v) sort(v.begin(), v.end(), greater<ll>());
#define srev(str) reverse(str.begin(), str.end());
#define loop(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];

void solve()
{
    inn(n) inn(q)
        //     set<ll>
        //         point;
        // for (int i = 0; i < n; ++i)
        // {
        //     point.insert(i);
        // }
        // while (q--)
        // {
        //     inn(l) inn(r) inn(k) int cnt = 0;
        //
        //     auto it = point.lower_bound(l), ed = point.upper_bound(k);

        //     while (it != ed && (*it <= r && *it > l))
        //     {
        //         cnt++;
        //         it++;
        //     }
        //     out(cnt)
        // }
        vector<ll>
            v(n);
    loop(i, 0, n) cin >> v[i];
    srt(v);
    while (q--)
    {
        inn(l) inn(r) inn(k)
            ll ans = 0;
        loop(i, 0, n)
        {
            if (v[i] >= l and v[i] <= r)
                ans++;
        }
        cout << ans * k << "\n";
    }
}
int main()
{
    AHSAN
    int t;
    cin >> t;
    while (t--)
        solve();
}