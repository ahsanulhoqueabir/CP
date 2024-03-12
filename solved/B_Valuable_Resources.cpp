// https://codeforces.com/contest/485/problem/B

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
    lld max_x=-1*(1e9+9),min_x=1e9+9,max_y=-1*(1e9+9),min_y=1e9+9,x,y,n; 
    cin >>n;
    while(n--)
    {
        cin>>x>>y;
        if(x>max_x)max_x=x;
        if(x<min_x)min_x=x;
        if(y>max_y)max_y=y;
        if(y<min_y)min_y=y;
    }
     x=max((max_y-min_y),(max_x-min_x));
     cout << (x*x) nl
}
int main()
{
    AHSAN
    int t=1;
    // cin>>t;
    while (t--) solve();
}