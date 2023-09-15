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
    lld n,k,c=1,x=0; in(n) in(k)
    lld a[n];
    FOR(i,0,n) in(a[i])
    sort(a,a+n,dsc);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]-a[i+1]<=k)
        {
            c++;
            if(c>x) x=c;
        }
            else c=1;
    }
    if(x>c) outn(n-x)
    else outn(n-c)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}