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
#define dsc greater<lld>()
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld n,x; in(n) in(x)
    vector<lld>v(n);
    FOR(i,0,n) in(v[i])
    lld l=1,h=INT_MAX,a=INT_MAX;
    while((l-h)<1)
    {
        lld m=(h-l)/2 +l,r=0;
        for(auto &i: v)
        {
            if(m>i) r+=(m-i);
        }
        if(r<=x)
        {
            a=m;
            l=m+1;
        }
        else h=m-1;
    }
    outn(a)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}