
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

#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


int solve()
{
   	lld n,c;
    cin >> n;
    lld a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n/3;i++)
	{
		if(n%i==0)
			for(int j=0;j<i;j++)
			{
				int k=j;
				while(a[k] && k<n) 
                    k=k+i;
				if(k>=n)
				{
					py
					return 0;
				}
			}
	}
	pn
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}
