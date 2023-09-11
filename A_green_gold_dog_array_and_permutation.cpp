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
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld n,a,f; in(n)
    vector<pair<int,int>>v;
    FOR(i,0,n)
    {
        in(a) 
        v.push_back({a,i});
    }
    srt(v)
    f=n;
    FOR(i,0,n)
    { 
        v[i].first=f; 
        f--;
    }
    lld r[n];
    FOR(i,0,n)
    {
        r[v[i].second]=v[i].first;
    }
    FOR(i,0,n) outs(r[i]) nl

}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}