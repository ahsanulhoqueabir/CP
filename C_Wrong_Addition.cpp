// https://codeforces.com/contest/1619/problem/C

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
    lld a,s,ans=0,p=1,x,t;
	cin >>a >>s;
	while(s!=0) 
    {
		x = s%10;
		s=s/10;
		t = a%10;
		a=a/10;
		if(t>x) 
        {
			x= x + 10*(s%10);
			s=s/10;
		}
		if((x-t ) > 9 || t>x) 
        {
			cout<< "-1" nl
			return;
		}
		ans = ans + p*(x-t);
		p=p*10;
	}
	if(a!=0) 
    {
		cout << "-1" nl
		return;
	}
	cout << ans nl
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}