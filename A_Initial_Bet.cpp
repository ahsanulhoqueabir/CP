// https://codeforces.com/contest/478/problem/A

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
    lld a[5],s=0;
    FOR(i,0,5)
    {
        cin >> a[i];
        s+=a[i];
    }
    if(s%5==0 && s) cout << s/5 nl
    else cout << "-1" nl
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}