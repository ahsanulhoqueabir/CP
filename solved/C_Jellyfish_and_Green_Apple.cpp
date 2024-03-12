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
    lld n, m; in(n) in(m)
    // lld gc = __gcd(n, m);
    // n%= m;
    // lld mm = m / gc;
    // if ((mm & (mm - 1))) 
    // {
    //     outn(-1)
    //     return;
    // }
    // lld ans = 0;
    // while (n) 
    // {
    //     ans += n;
    //     n <<= 1;
    //     if (n>= m) 
    //     {
    //         n-=m;
    //     }
    // }
    // outn(ans)
    int x=0,ans=0;
    while(n!=0)
    {
        n%=m;
		ans+= n;
		n <<= 1;
        x++;
        if(x==1000) break;
    }
    if(x=1000 and n!=0) outn(-1)
    else outn(ans)
    
} 
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--) solve();
}