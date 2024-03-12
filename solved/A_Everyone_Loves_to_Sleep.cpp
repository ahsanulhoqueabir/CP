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
#define loop(i,x,n) for(lld i=x;i<n;i++)

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


void solve()
{
    lld n,h,m;
	cin>>n>>h>>m;
	lld tm=h*60+m;
	lld a=1510;
	while(n--)
	{
		cin>>h>>m;
		lld p=h*60+m;
		if(p<tm)p+=(24*60);
		a=min(a,abs(p-tm));
	}
	cout << a/60 <<" " << a%60 nl
}
int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}