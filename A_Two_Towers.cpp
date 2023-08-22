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
    int n,m,ct=0;
    cin >> n >> m;
    string s1,s2;
    cin >> s1 >> s2;
    srev(s2);
    string s = s1 + s2;
    FOR(i,0,m+n)
    {
        if(s[i]==s[i+1])
        ct++;
    }
    if(ct<2) py
    else pn
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}

// https://codeforces.com/problemset/problem/1795/A