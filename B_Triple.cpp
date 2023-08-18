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
#define loop(i,x,n) for(lld i=x;i<n;i++)

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

void solve()
{
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int f = 0;
        for(int i=0;i<n-2;i++)
        {
            if(a[i]==a[i+1] && a[i]==a[i+2])
            {
                f =1;
                cout<<a[i]<<endl;
                break;
            }
        }
        if(f==0)
            cout<<"-1"<<endl;
}
int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}