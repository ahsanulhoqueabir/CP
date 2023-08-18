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
    string s1,s2;
    cin >> s1 >> s2;
    lld ct=0;
    for(lld i=0;i<s1.size();i++)
    {
       lld ctt=0;
       for(lld j=0;j<s2.size();j++)
       {
        if(s1[i+j]==s2[j]) ctt++;
       }
       if(ctt == s2.size())
       {
        ct++;
        i+=(s2.size()-1);
       }
    }
    cout << ct nl
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}