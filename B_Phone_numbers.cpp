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
    lld n;
    cin >> n;
    string number;
    cin >> number;
    if(n%2==0) 
    {
        for(int i=0; i<n-2; i+=2)
        {
            cout<<number[i]<<number[i+1]<<"-";
        }
        cout<<number[n-2]<<number[n-1];     
    }
    else
    {
        for(int i=0; i<n-3; i+=2)
        {
            cout<<number[i]<<number[i+1]<<"-";
        }
        cout<<number[n-3]<<number[n-2]<<number[n-1];
    }
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}