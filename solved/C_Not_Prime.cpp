/*--------------------------------------------------------*
 *                                                         *
 *      **       *     *   ** ****       **      *     **  *
 *     *  *      *     *   *            *  *     *    ***  *
 *    ******     * * * *   *** ***     ******    *   *  *  *
 *   *      *    *     *         *    *      *   ***    *  *
 *  *        *   *     *   *** ***   *        *  **     *  *
 *_________________________________________________________*/

#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x << " ";
#define outn(x) cout << x << "\n";
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define nl cout << "\n";
#define vp vector<pair<ll, ll>>
#define dsc greater<ll>()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end());
#define dsrt(v) sort(v.begin(), v.end(), greater<ll>());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];
void solve()
{
    ll a,b; in(a) in(b)
    if(b<4) outn(-1)
    else if(a==b )
    {
        if(a%2==0) 
        { 
            outs(2) outn(a-2) 
        }
        else 
        {
            int i=2;
            int p=-1;
            for( i=2;i*i<=a;i++)
            {
                if(a%i==0)
                {
                    p=i;
                    break;
                }
            }
            if(p==-1 || a-p ==0) outn(-1)
            else 
            { 
                outs(p) outn(a-p) 
            }
        }
    }
    else 
    { 
        outs(2) outn(b-(b&1)-2) 
    }
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--) solve();
}