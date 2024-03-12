// https://codeforces.com/problemset/problem/146/A

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
// const lld N= 1e7 + 10;
// lld A[N];

void solve()
{
    lld n,ds1=0,ds2=0,f=0,ct=0; cin>>n;
    string s; cin >>s;
    FOR(i,0,n) {if(s[i]=='7' || s[i]=='4') {ct++;}}
    if(ct==n)
    {
    for(int i=0,j=n/2;i<n/2,j<n;i++,j++)
    {   
        ds1+=s[i];
        ds2+=s[j];
    }
        if((ds1==ds2)) py
        else pn
    }
    else pn

    // for(int i=0;i<n/2;i++)
    // {
    //     int tmp = s[i]-'0';
    //     if(tmp==7 || tmp==4 )
    //     {
    //         ds1+=tmp;
    //     }
    //     else
    //     {
    //         f=1;
    //         break;
    //     }
    // }
    // for(int i=n/2;i<n;i++)
    // {
    //     int tmp = s[i]-'0';
    //     if(tmp==7 || tmp==4 )
    //     {
    //         ds2+=tmp;
    //     }
    //     else
    //     {
    //         f=1;
    //         break;
    //     }
    // }
 
    // if(f==0 && (ds1==ds2)) py
    // else pn
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}