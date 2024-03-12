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
#define in(x) cin >> x;
#define out(x) cout << x;
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
    int n; cin >> n;
    vector<int> v(n + 1);
    for (lld i=0;i<n;i++) 
    {
        lld x; in(x)
        v[x] = i;
    }
    lld r = 0;
    for (lld i = 1; i < n; i++) 
    {
        if (v[i + 1] < v[i]) 
        {
            r++;
        }
    } out(r) 
    cout nl
    
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}