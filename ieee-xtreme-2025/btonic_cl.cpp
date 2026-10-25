#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(6);            \
    cout.setf(ios::fixed, ios::floatfield);

const ll M=1e9+7;

void Solve()
{
    ll m;
    cin>>m;
    vector<ll>r(m+1,0);
    vector<vector<vector<ll>>>dp(m+1,vector<vector<ll>>(m+1,vector<ll>(2,0)));
    
    for(ll v=1;v<=m;v++){
        dp[v][v][0]=1;
        dp[v][v][1]=1;
    }
    
    for(ll n=2;n<=m;n++){
        for(ll v=1;v<n;v++){
            for(ll pv=1;pv<=v;pv++){
                dp[n][v][0]=(dp[n][v][0]+dp[n-v][pv][0])%M;
            }
            for(ll pv=v;pv<n;pv++){
                dp[n][v][1]=(dp[n][v][1]+dp[n-v][pv][0])%M;
                dp[n][v][1]=(dp[n][v][1]+dp[n-v][pv][1])%M;
            }
        }
    }
    
    for(ll n=1;n<=m;n++){
        for(ll v=1;v<=n;v++){
            r[n]=(r[n]+dp[n][v][0])%M;
            r[n]=(r[n]+dp[n][v][1])%M;
        }
    }
    
    for(ll i=1;i<=m;i++){
        cout<<r[i];
        if(i<m)cout<<" ";
    }
    cout<<endl;
}

int main()
{

    fraction();
    optimize();

    int t = 1;
   // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case : " << i << " " << Solve();
        Solve();
    }

    return 0;
}
