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
#define outn(x) cout << x << "\n";
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
       lld n,k; in(n) in(k)
       multiset<lld> bags;
       for(lld i=0;i<n;i++)
       {
            lld a;in(a)
            bags.insert(a);
       }
       lld tc=0;
       for(lld i=0;i<k;i++)
       {
            auto last_it = (--bags.end()); 
            lld ct= *last_it;
            tc +=ct;
            bags.erase(last_it);
            bags.insert(ct/2);
       }
       outn(tc)  
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}