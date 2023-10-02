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
    lld n,mx=0,ans=0; in(n)
    int x=0;
    vector<int>v(n);
    FOR(i,0,n)
    {
        in(v[i])
        x^=v[i];
    }
    for(int i=0;i<v.size();i++)
    {
        if(x^v[i]==v[i])
        {
            ans=v[i];
            break;
        }
    } outn(ans)
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--) solve();
}