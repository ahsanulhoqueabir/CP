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
#define nl <<"\n";
#define srt(v) sort(v.begin(), v.end());
#define rev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
//const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
     lld n; in(n)
     lld d[n],s[n],r[n];
     FOR(i,0,n)
     {
         in(d[i]) in(s[i])
         r[i] = d[i] + (s[i]-1)/2;
     }
     sort(r,r+n);
     outn(r[0])
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
    
}