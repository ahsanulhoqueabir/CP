/*--------------------------------------------------------*
*                                                         *
*      **       *     *   ** ****       **      *     **  *
*     *  *      *     *   *            *  *     *    ***  *
*    ******     * * * *   *** ***     ******    *   *  *  *
*   *      *    *     *         *    *      *   ***    *  *
*  *        *   *     *   *** ***   *        *  **     *  *
*_________________________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x <<" ";
#define outn(x) cout << x << "\n";
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl cout <<"\n";
#define dsc greater<lld>()
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    string s1,s2;
    int a[128]={0};
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!= ' ')
        {
            lld x=(int)s1[i];
            a[x]++;
        }
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]!= ' ')
        {
        int x= (int)s2[i];
        a[x]--;
        }
    }
    int f=0;
    for(int i=0;i<128;i++)
    {
        if(a[i]<0) f=1;
    }
    if(!f) py
    else pn
    // FOR(i,0,128) outs(a[i])
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}