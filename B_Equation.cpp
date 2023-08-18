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
#define loop(i,x,n) for(lld i=x;i<n;i++)

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


void solve()
{
    ld a,b,c;
    cin>>a>>b>>c;
    ld d=b*b-4*a*c;
    if(a==0 and b==0 and c==0)
    {
        cout << "-1"; 
        return;
    }
    if(a==0 and b==0)
    {
        cout << 0 nl
        return ;
    }
    if(a==0)
    {
        cout << 1 nl
        cout<< fixed << setprecision(12) << (-c/b) nl
        return ;
    }
    if(d==0)
    {
        cout << 1 nl
        cout<< fixed <<  setprecision(12) << (-b+sqrtl(d))/2/a nl
    }
    else if(d<0)
    {
        cout << 0 nl
    }
    else
    {
        cout << 2 nl
        vector<ld>ans;
        ans.push_back((-b-sqrtl(d))/2/a);
        ans.push_back((-b+sqrtl(d))/2/a);
        srt(ans);
        cout<< fixed << setprecision(12) << ans[0] nl 
        cout << fixed << setprecision(12) << ans[1] nl
    }
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}