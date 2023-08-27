// https://codeforces.com/problemset/problem/960/A

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
    string str1,str2;
    cin >>str1;
    str2=str1;
    srt(str1);
    if(str1!=str2) pn
    else
    {
        lld a=0,b=0,c=0;
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]=='a') a++;
            if(str1[i]=='b') b++;
            if(str1[i]=='c') c++;
        }
        if((c==b && c!=0 && a!=0) || (c==a && c!=0 && b!=0)) py
        else pn
    }
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}