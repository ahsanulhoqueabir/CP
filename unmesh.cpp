#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define nl <<"\n";
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define RUN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void solve()
{
    int a,b; 
    cin >> a >> b;
    int x=__gcd(a,b);
    int p = b/x;
    int q=(a%=b);
    cout << x << endl;
    cout << q << endl;
    cout << (p & (p-1)) << endl;
    // cout << (x & (x+1)) << endl;
}
int main()
{
    RUN
    int t=1;
    //cin>>t;
    while (t--) solve();
}
/*--------------------------------------------------------*
*                                                         *
*      **       *     *   ** ****       **      *     **  *
*     *  *      *     *   *            *  *     *    ***  *
*    ******     * * * *   *** ***     ******    *   *  *  *
*   *      *    *     *         *    *      *   ***    *  *
*  *        *   *     *   *** ***   *        *  **     *  *
*_________________________________________________________*/