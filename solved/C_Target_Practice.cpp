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
    char c[11][11];
    for(lld i=1;i<11;i++)
    {
        for(lld j=1;j<11;j++)
        {
            in(c[i][j])
        }
    }
    lld r=0;
    for(lld i=1;i<11;i++)
    {
        for(lld j=1;j<11;j++)
        {
            if(c[i][j]=='X')
            {
                if(i<=5)
                {
                    if(j<=5)
                    {
                        r+=min(i,j);
                    }
                    else r+=min(i,11-j);
                }
                else
                {
                    if(j<=5) r+=min(11-i,j);
                    else r+=min(11-i,11-j);
                }
            }
        }
    }
    outn(r)
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}