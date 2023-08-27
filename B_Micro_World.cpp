// https://codeforces.com/problemset/problem/990/B

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
    lld n,k; cin >> n >> k;
    lld a[n];
    FOR(i,0,n) cin >> a[i];
    sort(a,a+n);
    lld ct=0,ans=0;
    FOR(i,0,n-1)
    {
        while(ct<n && a[i]==a[ct]) ct++;
        if(a[ct]-a[i]>k) ans++;
    }
    cout << ans nl
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}