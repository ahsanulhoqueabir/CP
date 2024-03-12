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
    lld n; cin >> n;
    lld a[n];
    loop(i,0,n) cin>>a[i];
    if(n==1 && a[0]!=15 && a[0]!=0) cout << "-1" nl
    else if(n==1 && a[n-1]==15) cout << "DOWN" nl
    else if(n==1 && a[n-1]==0) cout << "UP" nl
    else
    {
        if(a[n-1]>a[n-2] && a[n-1]<15) cout<< "UP" nl
        else if(a[n-1]>a[n-2] && a[n-1]==15) cout<< "DOWN" nl
        else if(a[n-1]<a[n-2] && a[n-1]>0) cout << "DOWN" nl
        else if(a[n-1]<a[n-2] && a[n-1]==0) cout << "UP" nl
        else cout << "-1" nl
    }
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}