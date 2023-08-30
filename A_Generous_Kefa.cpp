// https://codeforces.com/problemset/problem/841/A

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
    lld n,k; in(n) in(k)
    string s; in(s)
    int a[128]={0};
    for(int i=0;i<s.size();i++)
    {
        // int x = (int)s[i];
        a[(int)s[i]]++;
    }
    sort(a,a+128);
    if(a[127]>k) pn
    else py
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}