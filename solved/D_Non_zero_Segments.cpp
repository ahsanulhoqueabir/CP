/*-----------------------------------------*
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<bits/stdc++.h>
#define lld = long long int
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define nl <<endl;
#define tc cin >> t;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
const int N = 1e7 + 10;
long long int Arr[N];

void solve()
{
   
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    //while (t--) solve();
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int c=0;
    for(int i=0;i<n;i++)
    {
        int s1=a[i];
        int s2=0;
        if(s1>0)
        {
            for(int j=i+1;j<n;++j)
            {
                s2+=a[j];
                if((-s2)==(s1))
                {
                    c++;
                    break;
                }
            }
        }
        else
        {
           for(int j=i+1;j<n;++j)
            {
                s2+=a[j];
                if((s2)==(-s1))
                {
                    c++;
                    break;
                }
            } 
        }
    }
    printf("%d",c);
}