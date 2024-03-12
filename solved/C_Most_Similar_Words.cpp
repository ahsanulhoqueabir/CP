// https://codeforces.com/problemset/problem/1676/C

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


void solve()
{
    int m,n;
    cin >> m>>n;
    char sa[n][55],arr[n];
    for(int i=0;i<n;i++)
    {
        cin>> sa[i];
    }
    for (int i = 1; i < n; i++) 
    {
        for (int j = 1; j < n; j++) {
            if (strcmp(sa[j - 1], sa[j]) > 0) {
                strcpy(arr, sa[j - 1]);
                strcpy(sa[j - 1], sa[j]);
                strcpy(sa[j], arr);
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<< sa[i] nl
    }
    
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}