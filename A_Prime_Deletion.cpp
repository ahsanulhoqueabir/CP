// https://codeforces.com/contest/1861/problem/A

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
    string s; in(s)
    lld a,b;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') a=i;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='3') b=i;
    }
    if(a<b) out("13") 
    else out("31")
    cout nl
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}