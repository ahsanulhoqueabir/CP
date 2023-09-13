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
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];
void solve()
{
    string s1,s2,s3,s4; in(s1) in(s2)
    lld ct1=0,ct2=0,i=0,j=0;
    while (s1[i]=='0') i++;
    while (s2[j]=='0') j++;
    s3=s1.substr(i,(s1.size()-i));
    s4=s2.substr(j,(s2.size()-j));

    if((s3.size()) < (s4.size())) cout << "<" nl
    else if((s3.size()) > (s4.size())) cout << ">" nl
    else
    {
        if(s3==s4) cout << "=" nl
        else
        {
            if(s3<s4) cout << "<" nl
            else cout << ">" nl
        }
    }    
}
int main()
{
    AHSAN
    int t=1;
    //cin>>t;
    while (t--) solve();
}