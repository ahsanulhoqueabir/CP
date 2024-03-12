// https://codeforces.com/problemset/problem/707/A

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
    lld n,m,f=0; cin >> n >> m;
    char C[n][m];
    for(lld i=0;i<n;i++)
    {
        for(lld j=0;j<m;j++)
        {
            cin >> C[i][j];
            if((C[i][j] == 'C') || (C[i][j] == 'M') || (C[i][j] == 'Y')) f=1; 
        }
    }
    if(f==1) cout << "#Color";
    else cout << "#Black&White";
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}