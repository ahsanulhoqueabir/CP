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
vector<string>valid;
void generate(string &s,int open,int close)
{
    if(open==0 and close==0) 
    {
        valid.push_back(s);
        return;
    }
    if(open>0) 
    {
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();
    }
    if(close>0)
    {
        if(open<close)
        {
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();
        }
    }
}
void solve()
{
    
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
    lld n; in(n)
    string s;
    generate(s,n,n);
    
}