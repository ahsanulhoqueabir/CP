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
#define vp vector<pair<ll, ll>>
#define dsc greater<ll>()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end());
#define dsrt(v) sort(v.begin(), v.end(), greater<ll>());
#define srev(str) reverse(str.begin(), str.end());
#define loop(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];
void solve()
{
    ll n,b,s=0; in(n) in(b)
    ll a[n];
    loop(i,0,n) 
    {
        in(a[i])
        s+=a[i];
    }
    if(s<n) pn
    else 
    {
        s=s%n;
        if(b==0 and s!=0) pn
        else py
    }
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--) solve();
}