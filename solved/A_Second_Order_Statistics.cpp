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
    lld n,f=0;
    cin >> n;
    lld a[n],b[n];
    FOR(i,0,n) cin >> a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
       if(a[i]!=a[0])
       {
            cout << a[i];
            f=1;
            break;
       }
    }
   if(!f) pn
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}