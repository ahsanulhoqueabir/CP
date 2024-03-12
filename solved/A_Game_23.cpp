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
#define loop(i,x,n) for(lld i=x;i<n;i++)

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int N = 1e7 + 10;
int Arr[N];

void solve()
{
    lld n,m;
    cin>>n>>m;
    int ct=0,a;
    if(m%n==0)
    {
       a=m/n;
       while(a%3==0)
       {
           a/=3;
           ct++;
       }
      
       while(a%2==0)
       {
           a/=2;
           ct++;
           
       }
       if(a==1)
        cout<<ct;
       else
        cout<<-1 nl
    }
   else
   cout<<-1 nl
    
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}