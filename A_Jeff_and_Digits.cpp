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
#define FOR(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];
void solve()
{
    ll n,x=0,y=0; in(n)
    vector<ll>v(n);
    FOR(i,0,n)
    {
        ll a; in(a)
        (a==5)? (x++) : (y++);
    }
    if(y == 0) 
    {
		outn(-1)
		return;
	}
	if(x/9==0) 
    {
		outn(0)
		return;
	}
	for(int i=0;i<(x-(x%9));i++) out(5)
	for(int i=0;i<y;i++) out(0)
}
int main()
{
    AHSAN
    int t = 1;
    // cin>>t;
    while (t--) solve();
}