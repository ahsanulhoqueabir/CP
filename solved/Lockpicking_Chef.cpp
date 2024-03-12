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
const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld n,m; in(n) in(m)
    string s, k; in(s) in(k)
    lld mmoves = N;
    for (lld i=0;i<=(n-m);i++) 
    {
        lld moves = 0;
        for (lld j=0;j<m;j++) 
        {        
            lld d = abs(s[i+j] - k[j]);
            moves += min(d,(10-d));
        }
        mmoves =min(mmoves, moves);
    } outn(mmoves)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}