// https://codeforces.com/problemset/problem/584/A

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
#define outn(x) cout << x << "\n";
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl <<"\n";
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld n,t,s,f=0; in(n) in(t)
    if(n<2 && t>9) out(-1)
    else 
    {
        out(t)
        if(t%10==0) { FOR(i,1,n-(t/10)) out(0) }
        else {FOR(i,1,n) out(0)}
    }
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}