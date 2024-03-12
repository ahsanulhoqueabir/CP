// https://codeforces.com/contest/1619/problem/B

/*-----------------------------------------*
*                                          * 
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl <<"\n";
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)

#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


void solve()
{
    lld n;
    cin >> n;
    // set<lld>a;
    // for(int i=1;i*i<=n;i++) a.insert(i*i);
    // for(int i=2;i*i*i<=n;i++) a.insert(i*i*i);
    // cout << a.size() nl
    lld r =(int) sqrt(n)+(int)cbrt(n)-(int)sqrt(cbrt(n));
    cout << r nl
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}