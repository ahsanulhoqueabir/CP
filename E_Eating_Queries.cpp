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
#define dsrt(v) sort(v.begin()+1, v.end()+1, greater<ll>());
#define srev(str) reverse(str.begin(), str.end());
#define loop(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];
ll v[200000];
void solve()
{
    ll n,q; in(n) in(q)
    // vector<ll>v(n);
    for (ll i=1;i<=n;i++) in(v[i])
    // dsrt(v)
    // vector<ll>vv(n);
    sort(v+1,v+n+1,greater<ll>());
    // vv[0]=v[0];
    // for(int i=1;i<n;i++)
    // {
    //     vv[i]=vv[i-1]+v[i];
    // }
    for(ll i=1;i<=n;i++) v[i]+=v[i-1];
    while(q--)
    {
        ll p; in(p)
        ll ans=lower_bound(v+1,v+n+1,p)-v;
        if(ans>n) outn(-1) 
        else outn(ans);
    }
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--) solve();
}