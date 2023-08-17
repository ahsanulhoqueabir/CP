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
    lld n;
    cin>>n;
    lld a[n],b[n];
    loop(i,0,n) 
    {
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    lld p=b[n-1];
    lld q=b[n-2];
    for(lld i=0;i<n;i++)
    {
        if(a[i]!=p)
            a[i]=a[i]-p;
        else 
            a[i]=a[i]-q;
    }
    for(lld i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout nl;
}
int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}