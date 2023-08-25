// https://codeforces.com/problemset/problem/1862/A

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


void solve()
{
    lld n,m;
    cin >> n>>m;
    char _a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> _a[i][j];
        }
    }
    lld v=0,i=0,k=0,a=0;
    lld x=0,y,z;
    string s="vika";
    for(lld i=0;i<m;i++)
    {  
        if(x>=4) break;
        else
        {
            for(lld j=0;j<n;j++)
            {
              if(_a[j][i]==s[x])
              {
                 x++;
                 break;
              }
            }
        }
        
    }
    // if(v==1 and k==1 and i==1 and a==1) py
    if(x>=4) py
    else pn
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}