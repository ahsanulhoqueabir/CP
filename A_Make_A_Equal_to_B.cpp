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
    lld n,cnt1=0,cnt2=0,cnt=0,f=1; in(n)
    lld a[n],b[n];
    FOR(i,0,n) { in(a[i]) if(a[i]==1) cnt1++; }
    FOR(i,0,n) { in(b[i]) if(b[i]==1) cnt2++; }
    FOR(i,0,n) { if(a[i]!=b[i]) cnt++;}
    f+= abs(cnt1-cnt2);
    outn(min(f,cnt))
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}