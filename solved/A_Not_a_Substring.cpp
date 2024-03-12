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
   
    string s; 
    cin >>s;
    if(s == "()") 
    {
        cout << "NO" << "\n";
    }
    else
    {
    py
    int ct=0,ctt=0;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]=='(' && s[i+1]!=')') || (s[i]!='(' && s[i+1]==')')) ct++;
        if(s[i]==')') ctt++;
    }
    int Max=max(ct,ctt);
    
    for(int i=0;i<2*ct;i++) cout << "(";
    for(int i=0;i<2*ct;i++) cout << ")";
    cout nl

    }

}
int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}