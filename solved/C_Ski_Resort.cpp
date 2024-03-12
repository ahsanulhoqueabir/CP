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
        lld t,n,k,q;
        cin>>n>>k>>q;
        lld ar[n],ct=0,r=0;
 
        FOR(i,0,n)
        {
            cin>>ar[i];
            if(ar[i]<=q) ct++;
            else ct=0;
            if(ct>=k)
            r+=ct+1-k;
        }
 
        cout<<r nl
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}