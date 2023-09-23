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
    lld n; in(n)
    vector<lld> v(n);
    FOR(i,0,n) in(v[i])
    vector<lld> v1;
    lld m=*min_element(v.begin(),v.end());
    FOR(i,0,n)
    {
        if(v[i]==m)
        {
           v1.push_back(i);
        }
   }
   lld r=INT_MAX;
   for(int i=0;i<v1.size()-1;i++)
   {
       r= min(r,(v1[i+1]-v1[i]));
   }
    outn(r)
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}