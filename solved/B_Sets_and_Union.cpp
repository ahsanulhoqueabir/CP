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
    lld n; in(n)
    // vector<set<lld>> vs;
    // // set<lld>ans;
    // FOR(i,0,n)
    // {
    //     lld k; in(k)
    //     set<lld>s;
    //     FOR(i,0,k)
    //     {
    //         lld a; in(a)
    //         s.insert(a);
    //         // ans.insert(a);
    //     }
    //     vs.push_back(s);
    // }
    // lld r=0;
    // for(lld i=0;i<n;i++)
    // {
    //     set<lld>ans;
    //     for(lld j=0;j<n;j++)
    //     {
    //         if(i!=j)
    //         {
    //             ans.insert(vs[j].begin(),vs[j].end());
    //         }
    //     }
    //     lld sz= ans.size();
    //     r=max(r,sz);
    // }
    // if(r) outn(r-1)
    // else outn(0)
    set<lld>s;
    vector<vector<lld>>v;
    for(lld i=0;i<n;i++)
    {
        lld x; in(x)
        vector<lld>v1;
        for(lld i=0;i<x;i++)
        {
            lld a; in(a)
        s.insert(a);
        v1.push_back(a);

        }
        v.push_back(v1);
    }
    lld ans=0;
    for(auto it: s)
    {
        set<lld >tmp;
        for(auto i:v)
        {
            lld f=1;
            for(auto j:i) 
            if(j==it) f=0;
            if(f==1) for(auto z:i) tmp.insert(z);
        }
        // for(auto x:tmp) outs(x)
        ans = max(ans,(lld)tmp.size());
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