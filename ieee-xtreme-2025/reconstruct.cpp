#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int main(){
    const int64 mod = 998244353;
    long long target = 1247652;
    for(long long b=1; b<=200; b++){
        long long inv = 1;
        long long a = target;
        // compute numerator as (target * b) mod M
        long long num = (target * (b % mod)) % mod;
        if(num > mod/2) num -= mod;
        double val = (double)num / (double)b;
        cout<<b<<" -> "<<num<<"/"<<b<<" ~ "<<val<<"\n";
    }
    return 0;
}
