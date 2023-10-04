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
    string s; in(s)
    int l=s.size(),a=0,c=0,g=0,t=0,ans=0;
    for(int i=0;i<l;)
    {  
        int x=0;
        if(s[i]=='A') 
        {
            while (s[i]=='A')
            {
                x++;
            }
                i+=x;
            ans=max(x,ans);
        }
        if(s[i]=='C') 
        {
            while (s[i]=='C')
            {
                x++;
            }
                i+=x;
            ans=max(x,ans);
        }
        if(s[i]=='G') 
        {
            while (s[i]=='G')
            {
                x++;
            }
                i+=x;
            ans=max(x,ans);
        }
        if(s[i]=='T') 
        {
            while (s[i]=='T')
            {
                x++;
            }
                i+=x;
            ans=max(x,ans);
        }
        
    }
    outn(ans)
}
int main()
{
    AHSAN
    int t = 1;
    // cin>>t;
    while (t--) solve();
}