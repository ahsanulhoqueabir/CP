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
    lld n,x,co=0,ce=0; in(n) in(x)
    lld a[n];
    FOR(i,0,n)
    {
        in(a[i])
        if(a[i]%2==0) ce++;
        else co++;
    }
   if(co>=1 && !(x==n && co%2==0) && !(co==n && x%2==0)) py
   else pn
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}