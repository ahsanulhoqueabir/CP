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

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


void solve()
{
    lld n,ec=0,oc=0;
    cin>>n;
    lld a[n];
    for(int i=0;i<n;i++) 
    {
        cin >> a[i];
        if(a[i]%2==0) ec++;
        else oc++;
    }
    int ct=0;
    if(ec%2==0 and oc%2==0) py
    else
    {
        sort(a,a+n);
        for(int i=1;i<n;i++)
        {
            if( (a[i] - a[i-1]) == 1) 
            ct=1;
        }
        if(ct == 1) py
        else pn
    }
}

int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}