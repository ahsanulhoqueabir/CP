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

vector<vector<pair<int,ll>>> g;
int n;
map<pair<int,int>,ll> dt;
vector<ll> d;

void dfs(int u, int p, ll ds){
    d[u]=ds;
    for(auto e:g[u]){
        int v=e.first;
        ll w=e.second;
        if(v!=p){
            dfs(v,u,ds+w);
        }
    }
}

ll getDist(int x, int y){
    if(x==y)return 0;
    int mn=min(x,y),mx=max(x,y);
    if(dt.count({mn,mx}))return dt[{mn,mx}];
    d.assign(n+1,0);
    dfs(x,-1,0);
    ll rs=d[y];
    dt[{mn,mx}]=rs;
    return rs;
}

void Solve()
{
    cin>>n;
    g.resize(n+1);
    d.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
    int m;
    cin>>m;
    
    vector<int> a;
    ll la=0;
    
    while(m--){
        int t;
        cin>>t;
        
        if(t==1){
            ll x;
            cin>>x;
            x=(x^abs(la))%n+1;
            a.push_back(x);
        }
        else if(t==2){
            a.pop_back();
        }
        else{
            ll l,r,x;
            cin>>l>>r>>x;
            l=(l^abs(la))%a.size()+1;
            r=(r^abs(la))%a.size()+1;
            x=(x^abs(la))%n+1;
            
            if(l>r)swap(l,r);
            
            ll mx=LLONG_MIN;
            for(int i=l-1;i<r;i++){
                ll di=getDist(x,a[i]);
                mx=max(mx,di);
            }
            la=mx;
            cout<<mx<<endl;
        }
    }
}

int main()
{

    fraction();
    optimize();

    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    return 0;
}