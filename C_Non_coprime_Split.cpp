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
#define nl <<"\n";
#define srt(v) sort(v.begin(), v.end());
#define rev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld a,b; in(a) in(b)

   if(b<=3) outn(-1)
   else if(a==b )
   {
    if(a%2==0) { outs(2) outn(a-2) }
    else 
    {
        int i=2;
        int p=-1;
        for( i=2;i*i<=a;i++)
        {
            if(a%i==0)
            {
                p=i;
                break;
            }
        }
        if(p==-1 || a-p ==0) outn(-1)
        else { outs(p) outn(a-p) }
    }
}
else { outs(2) outn(b-(b&1)-2) }
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
    
}