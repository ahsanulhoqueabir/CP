// https://codeforces.com/contest/813/problem/A

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
    lld n,s,sum=0; cin >> n;
	while(n--)
    {
		cin >> s;
		sum+=s;
	}
	lld m,l,r,f=0; cin >> m;
	while(m--)
    {
		cin >> l >> r;
        if(f!=0) continue;
		if(sum>=l && sum<=r)f=sum+1;
		else if(l>sum)f=l+1;
	}
	cout << f-1 nl 
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}