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
    lld n,a,q; in(n) in(a) in(q)
    string s; in(s)
    lld ct = a,sum=a,f=0;
    if (n == a) f = 1;
    FOR(i,0,q)
    {
        if (s[i] == '+')
        {
            ct++;
            sum++;
            if(ct>=n) f=1;
        }
        else
            ct--;
    }
    if (sum<n) puts("NO");
    else
    {
        if (f==1) puts("YES");
        else puts("MAYBE");
    }
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}