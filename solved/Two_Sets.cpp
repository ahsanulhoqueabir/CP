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
#define all(v) v.begin(), v.end()
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
   lld n; in(n)
   lld s=n*(n+1)/2;
   if(s&1) pn
   else
   {
        outn("YES")
        lld ss= s>>1; 
        // outn(ss)
        lld set1[n],set2[n];
        lld x=0,y=0;
        lld a=n;

        while(a>0) 
        {
            if(ss-a>=0) 
            {
                set1[x++]=a;
                ss-=a;
            } 
            else 
            {
                set2[y++]=a;
            }
            a--;
        }
        outn(x)
        FOR(i,0,x) outs(set1[i]) nl
        outn(y)
        FOR(i,0,y) outs(set2[i]) nl    
   }
}
int main()
{
    AHSAN
    int t = 1;
    // cin>>t;
    while (t--) solve();
}