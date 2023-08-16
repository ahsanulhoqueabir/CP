/*-----------------------------------------*
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<bits/stdc++.h>
#define lld  long long int
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
   // while (t--) solve();
   int n,m;
   cin>>n>>m;
   while (m--)
   {
        int a,b,d;
        cin>>a>>b>>d;
        Arr[a]+=d;
        Arr[b+1] -=d;

   }

   for(int i=1;i<=n;++i)
   {
        Arr[i] +=Arr[i-1];
   }  
   lld max=-1;
   for(int i=1;i<=n;++i)
   {
    if(max<Arr[i])
    {
        max= Arr[i];
    }
   }
   cout << max nl
}