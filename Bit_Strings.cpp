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
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x << " ";
#define outn(x) cout << x << "\n";
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define nl cout << "\n";
#define vp vector<pair<lld, lld>>
#define dsc greater<lld>()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end());
#define dsrt(v) sort(v.begin(), v.end(), greater<lld>());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i, x, n) for (lld i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    ll n; in(n)
    ll ans=1;
    ll M=1e9+7;
    while (n--)
    {
        ans<<=1;
        ans%=M;
    }
    outn(ans)
}
int main()
{
    AHSAN
    int t = 1;
    // cin>>t;
    while (t--) solve();
}