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
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl <<"\n";
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define loop(i,x,n) for(lld i=x;i<n;i++)

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
const int N = 1e6 + 10;
lld A[N];
void count()
{
    for(lld i=1;i<N;i++)
    {
        int ct=0;
        for(lld j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                ct++;
            }
            if(ct>3)
            {
                A[i]=0;
                break;
            }
            if(ct<=3)
            {
                A[i]=1;
            }
        }
    }
}

void solve()
{
    lld n;
    cin>>n;
    if(A[n]==0) pn cout nl
    else py cout nl
}
int main()
{
    speed
    int t=1;
    cin>>t;
    while (t--) solve();
}