// https://codeforces.com/contest/1861/problem/B

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
    string s1,s2; in(s1) in(s2)
    lld f=0;
    for(lld i=0;i<s1.size();i++)
    {
        if((s1[i]=='0' and s2[i]=='0') and (s1[i+1]=='1' and s2[i+1]=='1')) f=1;
    }
    if(f==1) py
    else pn
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}