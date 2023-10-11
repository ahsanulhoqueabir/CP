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
#define loop(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];
int solve()
{
    int n,a,b; in(n) in(a) in(b)
    vector<int>v(n);
    loop(i,0,n) in(v[i])
    srt(v)
    int ct=0,i=0,j=n-1;
    for(int i=0;i<n;i++) 
    {
        int lo=a-v[i];
        int hi=b-v[i];
    
    for(int j=0;j<n;j++) 
    {
        if(i!=j and a<=v[i]+v[j] and v[i]+v[j]<=b) 
        {
            ct++;
        }
    }
    }
    return ct;
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int x=solve();
        cout << "Case " << k << ":" << x/2 << "\n";
    }
}