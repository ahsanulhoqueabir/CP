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
    lld x,y,n;
    cin >> x >> y >> n;
    vector<int>v;
    lld ct=1;
    FOR(i,0,n)
    {
        v.push_back(y);
        y-=ct;
        ct++;
    }
    if(v[v.size()-1]<x) cout << "-1" nl
    else
    {
        cout << x << " ";
        for(int i=v.size()-2;i>=0;i--) cout << v[i] << " ";
        cout nl
    }
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}