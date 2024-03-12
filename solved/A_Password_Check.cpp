// https://codeforces.com/problemset/problem/411/A

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
    string s;
    cin>>s;
    lld l=s.size();
    if(l<5) cout << "Too weak" nl
    else
    {
        lld ct=0,d=0,sl=0,cl=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='0' && s[i]<='9')) d++; 
            else if(s[i]>='a' && s[i]<='z') sl++;
            else if(s[i]>='A' && s[i]<='Z') cl++;
        }
        if(d!=0 && sl!=0 && cl!=0) cout << "Correct" nl
        else  cout << "Too weak" nl
    }
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}