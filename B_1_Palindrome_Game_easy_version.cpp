// https://codeforces.com/problemset/problem/1527/B1


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
    string s;
    lld n,zc=0;
    cin>>n>>s;
    FOR(i,0,n){
        if(s[i]=='0') zc++;
    }
    if(zc==1) cout<<"BOB\n";
    else if(zc%2) cout<<"ALICE\n";
    else cout<<"BOB\n";
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}