#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    vector<int> perm(n);
    iota(perm.begin(),perm.end(),0);
    long long sum=0;
    long long cnt=0;
    long long absSum=0;
    long long sqSum=0;
    map<int,int> freq;
    long long posSum=0;
    do{
        int total=0;
        for(int i=0;i<n;i++){
            int r=i, c=perm[i];
            bool black = ((r+c)%2==1); // assume top-left white
            total += black?1:-1;
        }
        sum += total;
        absSum += abs(total);
        sqSum += 1LL*total*total;
        posSum += max(total,0);
        freq[total]++;
        cnt++;
    }while(next_permutation(perm.begin(),perm.end()));
    cout<<sum<<"/"<<cnt<<endl;
    const long long mod=998244353;
    auto modpow=[&](long long a,long long e){long long r=1;while(e){if(e&1)r=r*a%mod;a=a*a%mod;e>>=1;}return r;};
    long long val = ((sum%mod)+mod)%mod;
    long long denom = modpow(cnt%mod, mod-2);
    cout << val*denom%mod << endl;
    long long absVal = absSum%mod;
    cout << absVal*denom%mod << endl;
    long long sqVal = sqSum%mod;
    cout << sqVal*denom%mod << endl;
    for(auto &kv:freq){
        cout<<kv.first<<":"<<kv.second<<"\n";
    }
    long long posVal = posSum%mod;
    cout << posVal*denom%mod << endl;
}
