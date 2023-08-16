// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y?fbclid=IwAR0YfBh1j81X0mKrL7zcfO5ykzHfVAn0VyKTDne2K89Pj7tUfCuuEAA1Hio

/*-----------------------------------------*
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define nl <<endl;
#define tc cin >> t;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
const int N = 1e6 + 10;
long long int Arr[N];

void solve()
{
    Arr[0]=0;
    lld n,q;
    cin >> n >> q;
    lld a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        Arr[i]= Arr[i-1]+a[i];
    }
    while ( q-- )
    {
        int l,r;
        cin>>l>>r;
        cout << Arr[r]-Arr[l-1] nl
    }
}
int main()
{
    speed
    int t=1;
    //cin>>t;
    while (t--) solve();
}