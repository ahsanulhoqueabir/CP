/*--------------------------------------------------------*
 *                                                         *
 *      **       *     *   ** ****       **      *     **  *
 *     *  *      *     *   *            *  *     *    ***  *
 *    ******     * * * *   *** ***     ******    *   *  *  *
 *   *      *    *     *         *    *      *   ***    *  *
 *  *        *   *     *   *** ***   *        *  **     *  *
 *_________________________________________________________*/

#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x << " ";
#define outn(x) cout << x << "\n";
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define nl cout << "\n";
#define vp vector<pair<lld, lld>>
#define dsc greater<lld>()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end());
#define dsrt(v) sort(v.begin(), v.end(), greater<lld>());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i, x, n) for (lld i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    string s; in(s)
    int a[128]={0};
    int l=s.size(),ct=0;
    char c;
    for(int i=0;i<l;i++)
    {
        int x=(int)s[i];
        a[x]++;
    }
    for(int i=0;i<128;i++)
    {
        if(a[i]&1) 
        {
            ct++;
            c=char(i);
        }
    }
    if(ct>1) outn("NO SOLUTION")
    else
    {
        string ss;
        for (int i=0;i<128;i++) 
        {
            if(a[i]%2==0) 
            {
                for(int j=0;j<a[i]/2;j++) 
                {
                    ss += (char)(i);
                }
            }
        }
        string s2=ss;
        srev(ss)
        if(ct==1) 
        {
            cout << s2;
            for(int i=0;i<a[(int)c];i++) out(c)  outn(ss) 
        }
        else cout << (s2+ss) << endl;    
    }
}
int main()
{
    AHSAN
    int t = 1;
    // cin>>t;
    while (t--) solve();
}