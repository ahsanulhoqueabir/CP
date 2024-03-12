/*--------------------------------------------------------*
*                                                         *
*      **       *     *   ** ****       **      *     **  *
*     *  *      *     *   *            *  *     *    ***  *
*    ******     * * * *   *** ***     ******    *   *  *  *
*   *      *    *     *         *    *      *   ***    *  *
*  *        *   *     *   *** ***   *        *  **     *  *
*_________________________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x <<" ";
#define outn(x) cout << x << "\n";
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
    lld n,x,r=0; in(n) in(x)
    lld a[3][n];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++) in(a[i][j])
	}
    for(int i=0;i<3;i++)
    {
		for(int j=0;j<n;j++)
        {
			if((x|a[i][j])==x) r|=a[i][j];
			else break;
		}
	}
    if(r==x) py
    else pn
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}