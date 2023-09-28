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
#define vp vector<pair<lld,lld>>
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
    lld n,k,s=0; in(n) in(k)
    if(k<n) outn(-1)
    else
    {
        for(lld i=1;i<=n-2;i++)
        {
            if(i&1) 
            {
                outs(1)
                s+=1;
            }
            else 
            {
                outs(2)
                s+=2;
            }
        }
        lld x=k-s;
        if(x&1)
        {
            outs(1) outs(x-1)
        }
        else
        {
            int x=k-3*(n/2);
            outs(x)
        }
        nl
    }
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}