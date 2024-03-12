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
const lld N = 1e7 + 10;
lld Arr[N];

void solve()
{
    lld n,m,a,b;
    cin >> n>>m>>a>>b;
    float x=b/m;
    if(a<=x)
    {
      lld e=n*a;
      cout<<e;
    }
    else 
    {
        if(n%m==0)
        {
            lld c=n/m;
            lld sum=c*b;
            cout<<sum;
        }
        else
        {
            lld d=n%m;
            lld c=n/m;
            if(b<(d*a))
            {
                lld sum=(c*b) + b ;
                cout<<sum;
            }
            else
            {
            lld sum=(c*b) + (d*a);
            cout<<sum;
            }
        }
    }
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}