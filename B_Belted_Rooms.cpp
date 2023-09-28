/*--------------------------------------------------------*
 *                                                         *
 *      **       *     *   ** ****       **      *     **  *
 *     *  *      *     *   *            *  *     *    ***  *
 *    ******     * * * *   *** ***     ******    *   *  *  *
 *   *      *    *     *         *    *      *   ***    *  *
 *  *        *   *     *   *** ***   *        *  **     *  *
 *_________________________________________________________*/

#include <bits/stdc++.h>
#define lld long long int
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x << " ";
#define outn(x) cout << x << "\n";
#define py cout << "YES" \
                << "\n";
#define pn cout << "NO" \
                << "\n";
#define nl cout << "\n";
#define vp vector<pair<lld, lld>>
#define dsc greater<lld>()
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i, x, n) for (lld i = x; i < n; i++)
#define AHSAN                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    lld n; in(n)
    string s; in(s)
    int ans = 0;
    int gt = 0, ls = 0, eq = 0;
    for(int i=0;i<s.size();i++)
    {
        if (s[i] == '>') gt++;
        if (s[i] == '<') ls++;
        if (s[i] == '-') eq++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-' or s[(n+i-1)%n]=='-') ans++;
        else
        {
            if (s[i]=='>')
            {
                if(ls==0) ans++;
            }
            else if(s[i]=='<')
            {
                if (gt==0) ans++;
            }
        }
    } outn(ans)
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    while (t--)
        solve();
}