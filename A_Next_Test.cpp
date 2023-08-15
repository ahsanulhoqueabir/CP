/*-----------------------------------------*
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/
#include <bits/stdc++.h>
#define lld  long long int
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define nl <<endl;
#define tc int t; cin>>t;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{
    speed
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    //for(int i=0;i<n;i++) cout << a[i];
    int c = 1;
    for (int i=0;i<n;i++) 
    {
        if (a[i] == c) 
        {
            c++;
        }
    }

    printf("%d\n", c);
    
}