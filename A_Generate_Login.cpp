// https://codeforces.com/problemset/problem/909/A

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
    string s1,s2;
    cin >> s1 >> s2;
    cout << s1[0];
    for(int i=1;i<s1.size();i++)
    {
        if(s1[i]<s2[0]) 
        {
        cout << s1[i];
        } 
        if(s1[i]>=s2[0]) break;;
    }
    cout << s2[0];
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}