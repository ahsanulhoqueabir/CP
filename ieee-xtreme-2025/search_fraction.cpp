#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int main(){
    const int64 mod = 998244353;
    int64 val = 1247652;
    int64 limit = 1000000;
    for(int64 b=1; b<=limit; b++){
        int64 a = val * (b % mod) % mod;
        if(a > mod/2) a -= mod;
        if(labs(a) <= limit){
            cout << "b=" << b << " a=" << a << " fraction=" << a/(double)b << "\n";
            return 0;
        }
    }
    cout << "none" << endl;
    return 0;
}
