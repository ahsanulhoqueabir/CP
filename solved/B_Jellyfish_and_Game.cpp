/*--------------------------------------------------------*
 *                                                         *
 *      **       *     *   ** ****       **      *     **  *
 *     *  *      *     *   *            *  *     *    ***  *
 *    ******     * * * *   *** ***     ******    *   *  *  *
 *   *      *    *     *         *    *      *   ***    *  *
 *  *        *   *     *   *** ***   *        *  **     *  *
 *_________________________________________________________*/

#include <bits/stdc++.h>
#define lld long long int
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
    lld n,m,k; in(n) in(m) in(k)
    vector<int> a(n);
    vector<int> b(m);
    FOR(i,0,n) in(a[i])
    FOR(i,0,m) in(b[i])

    srt(a) srt(b)
    if(a[0]<b[m-1]) swap(a[0],b[m-1]);

    if(k%2==0)
    {
        srt(a) srt(b)
		swap(a[n-1],b[0]);
	}
	lld ans=0;
	for(int i=0;i<n;i++) ans+=a[i]; outn(ans)
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--) solve();
}