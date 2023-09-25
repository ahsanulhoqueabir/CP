/*--------------------------------------------------------*
*                                                         *
*      **       *     *   ** ****       **      *     **  *
*     *  *      *     *   *            *  *     *    ***  *
*    ******     * * * *   *** ***     ******    *   *  *  *
*   *      *    *     *         *    *      *   ***    *  *
*  *        *   *     *   *** ***   *        *  **     *  *
*_________________________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x <<" ";
#define outn(x) cout << x << "\n";
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl cout <<"\n";
#define vp vector<pair<lld,lld>>
#define dsc greater<lld>()
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const lld N= 1e7 + 10;
// lld A[N];
lld a[N],b[N];
void solve()
{
    lld n,c=0; in(n)
    for(lld i=0;i<=n;i++) b[i]=0;

    for(lld i=0;i<n;i++) in(a[i])
    
    for(lld i=n-1;i>=0;i--)
    {
        b[i]=b[i+1]+ (a[i]>=0? a[i]:0);
    }
    lld ans=0;
    for(lld i=0;i<n;i++)
    {
        ans = max(ans,(b[i+1]+(i%2==0?a[i]:0)));
    }
    outn(ans)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}