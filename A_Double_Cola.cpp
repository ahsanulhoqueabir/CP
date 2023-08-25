// https://codeforces.com/problemset/problem/82/A

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
    lld n;
    cin >> n;
    n--;
    int d= 1,ct=0;
    for(int i = 0; i < n; i += d) 
    {
		ct++;
		if(ct == 5) 
        {
			ct = 0;
			d *= 2;
		}
	}
    switch (ct)
    {
    case 4:
        cout << "Howard" nl
        break;
    case 0:
        cout << "Sheldon" nl
        break;
    case 1:
        cout << "Leonard" nl
        break;
    case 2:
        cout << "Penny" nl
        break;
    case 3:
        cout << "Rajesh" nl
        break;
    
    
    }
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}