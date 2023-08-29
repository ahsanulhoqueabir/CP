// https://codeforces.com/problemset/problem/4/C

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
// const lld N= 1e7 + 10;
// lld A[N];

void solve()
{
    lld n; cin>>n;
    map<string,int> m;
    FOR(i,0,n)
    {
        string s; cin >> s;
        if(m[s]==0) cout << "OK" nl
        else
        {
            cout<< (s + to_string(m[s])) nl
        }
        m[s]++;
    }
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}