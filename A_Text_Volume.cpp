// https://codeforces.com/problemset/problem/837/A

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
    lld n; cin >> n;
    string str;
    getline(cin,str);
    getline(cin,str);
    lld ct=0,m=0;
    for(int i=0;i<str.size();i++)
    {
        if(isupper(str[i])) ct++;
        m=max(m,ct);
        if(str[i]==' ') ct=0;
    }
    out(m)
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}