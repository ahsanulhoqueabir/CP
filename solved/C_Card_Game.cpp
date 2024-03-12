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
    lld n,ans=0; in(n)
    // vector<lld>v;
    lld v[n];
    FOR(i,0,n) 
    {
        in(v[i])
        if(v[i]>0) ans+=v[i];
    }
    if(n==1) outn(ans)
    else if(v[0]<0 and v[1]>0)
    {
        if(v[0] + v[1]>0) outn(ans+v[0])
        else outn(ans - v[1])
    }
    else outn(ans)

}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}