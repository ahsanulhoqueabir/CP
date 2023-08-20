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
    string s,s1;
    cin>>s;
    lld l=s.size();
    lld f=0;
    for(int i=l-1; i>0; i--)
    {
        if(s[i]!='/') 
        {
            break;
        }
        else l--;
    }
 
    for(int i=0; i<l; i++)
    {
        if(f==0 && s[i]=='/')
        {
            cout<<s[i];
            f=1;
        }
 
        else if(s[i]!='/')
        {
            cout<<s[i];
            f=0;
        }
    }
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}