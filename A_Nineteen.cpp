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
#define FOR(i,x,n) for(lld i=x;i<n;i++)

#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


void solve()
{
    string s;
    cin>>s;
    lld n=0,i=0,e=0,t=0;
    for(int j=0;j<s.size();j++)
    {
        if(s[j]=='n') n++;
        if(s[j]=='i') i++;
        if(s[j]=='e') e++;
        if(s[j]=='t') t++;
    }
    // cout << n << " "<< i << " " << e << " " << " " << t nl 
    lld x=(n-1)/2;
    lld y=e/3;
    lld a[4]={x,y,i,t};
    sort(a,a+4);
    cout<< a[0] nl


}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}