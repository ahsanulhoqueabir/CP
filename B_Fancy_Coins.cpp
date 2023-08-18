/*-----------------------------------------*
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
#define loop(i,x,n) for(lld i=x;i<n;i++)

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


void solve()
{
    lld m, k, a1, a2;
    cin>>m>>k>>a1>>a2;

    if(a1>=m || (m%k<=a1 && m/k<=a2))
    {
        cout<<0<<"\n";
    }
    else
    {
        lld y = min(m/k,a2);
        lld x = min(m-k*y,a1);
        lld r = m-x-k*y;
        if(r%k==0){
            cout<<r/k<<"\n";
        }
        else if( (k - r%k) <= x ){
            cout<<(r/k)+1<<"\n";
        }
        else cout<<(r/k)+(r%k)<<"\n";
    }
}
int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}