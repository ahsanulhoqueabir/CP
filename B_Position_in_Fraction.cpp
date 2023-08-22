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
    ld a,b;
    char c;
    cin >> a>>b>>c;
    ld f= a/b;
    int fl=0,ct=0;
    // cout << f nl
    lld r= (100000000000) *(f - int(f));
    //  cout <<r;
    string s;
    s = to_string(r);
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==c)
        {
            fl=1;
            ct=i+1;
            break;
        }
    }
    if(fl==1) cout << ct;
    else cout << "-1";
    cout nl
    
}
int main()
{
    AHSAN
    cout << fixed << setprecision(12);
    int t=1;
    //cin>>t;
    while (t--) solve();
}