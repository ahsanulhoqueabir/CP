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
    lld n,k,s=0,m,r=1; in(n) in(k)
    lld a[n];
    FOR(i,0,n) { in(a[i]) s+=a[i];}
    m=s;
	for(lld i=1;i<n-k+1;i++)
    {
		s=s-a[i-1]+a[k+i-1];
		if(s<m)
        {
			m=s;
			r=i+1;
		}
	} 
    outn(r)
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}