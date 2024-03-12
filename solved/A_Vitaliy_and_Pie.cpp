// https://codeforces.com/contest/525/problem/A

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
    lld n; cin >> n;
    string s; cin >>s;
    map<char,int>m;
    lld r=0;
    for(int i=1;i<s.size();i+=2)
    {
        if(s[i-1]!=s[i]+32)
        {
            m[s[i-1]]++;
            if(m[s[i]+32]>=1)
            {
                m[s[i]+32]--;
            }
            else r++;
        }
    }
    cout << r nl
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}