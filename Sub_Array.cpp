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
#define vp vector<pair<ll, ll>>
#define dsc greater<ll>()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end());
#define dsrt(v) sort(v.begin(), v.end(), greater<ll>());
#define srev(str) reverse(str.begin(), str.end());
#define loop(i, x, n) for (ll i = x; i < n; i++)
#define AHSAN  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const ll N= 1e7 + 10;
// ll A[N];
void solve()
{
    
}
int main()
{
    AHSAN
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i=0;i<n;i++)  cin >> v[i];
        int nb =1;
        int ct =1;

        for (int i=1;i<n;i++) 
        {
            if (v[i] == v[i-1]) ct++;
            else 
            {
                nb+=(ct*(ct+1))/2;
                ct=1;
            }
        }
        int x=(n*(n+1)/2);
        int result=x-nb;

        cout << "Case " << i << ": " << result; nl
    }
}