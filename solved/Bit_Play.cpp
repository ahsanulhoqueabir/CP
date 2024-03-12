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
#define vp vector<pair<lld,lld>>
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
     int n; in(n)
     string s; in(s)
     vector<int> v;
     for(int i=2;i<n;i+=2)
     {    
        char x,y,z;
         x = s[i-2];
         y = s[i-1];
         z = s[i];
         
         if(x!=y)
         {
             if(z=='1')
             {
                 v.push_back(2);
             }
             else
             {
                 v.push_back(1);
             }
        }
        else if(x=='1')
        {
             if(z=='1')
             {
                 v.push_back(2);
             }
             else
             {
                 v.push_back(1);
             }
         }
         else
         {
             if(z=='1')
             {
                 v.push_back(0);
             }
             else
             {
                 v.push_back(3);
             }
         }   
     }
     long long ans = 1;
     int mod = 1e9 + 7;
     for(auto val:v){
         ans*=val;
         ans%=mod;
     }
    outn(ans)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}