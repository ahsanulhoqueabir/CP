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
#define V vector<lld>
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld x,y,ct=0; in(x) in(y)
    V v(x);
    for(auto &i:v) in(i)
    // srt(v)
    sort(v.begin(),v.end(),dsc);
    for(lld i=0;i<x;i++)
    {
        if((ct < v[i]) and (y<=v[i]))
        {
            ct+=v[i];
        }
        else
        {
            y-=v[i];
        }
    }
    outn(ct)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}