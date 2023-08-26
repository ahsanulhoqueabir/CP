/*-----------------------------------------*
*                                          * 
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
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
    lld n,k; cin >> n >>k;
    string s; cin>> s;
    if(k%2==0)
    {
        srt(s);
        cout << s nl
        return;
    }
    vector<array<int,2>> ct(26);
    FOR(i,0,n)
    {
        ct[s[i]-'a'][i%2]++;
    }
    string ans="";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(ct[j][i%2]>0)
            {
                ct[j][i%2]--;
                ans+=(j+'a');
                break;
            }
        }
    }
    cout << ans nl
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}