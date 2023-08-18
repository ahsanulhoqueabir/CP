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
    string s1,s2,s3,s4;
    cin >> s1 >> s2;
    lld ct1=0,ct2=0;
    if(s1[0]=='0')
    {
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]=='0')
            ct1++;
            else break;
        }
    }
    for(int i=0;i<(s1.size()-ct1);i++)
    {
        s3[i]=s1[ct1+i];
    }
    if(s2[0]=='0')
    {
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]=='0')
            ct2++;
            else break;
        }
    }
    cout << s1 << " " << s2 << s3 nl
    cout << ct1 << " " << ct2 nl
    
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}