#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        ll n;
        cin >> n;
        
        bool found = false;
        
        if(n > 1) {
            ll a = 1, b = n, c = n - 1;
            if(c > 0 && a != b && a != c && b != c && (a ^ b ^ c) == n) {
                cout << a << " " << b << " " << c << "\n";
                found = true;
            }
        }
        if(!found) {
            for(ll a = 1; a <= min(n + 1000, 100000LL) && !found; a++) {
                for(ll b = a + 1; b <= min(n + 1000, 100000LL) && !found; b++) {
                    ll c = 2 * n - a - b;
                    if(c > 0 && c != a && c != b) {
                        if((a ^ b ^ c) == n) {
                            cout << a << " " << b << " " << c << "\n";
                            found = true;
                        }
                    }
                }
            }
        }
        if(!found) {
            cout << "-1\n";
        }
    }
    return 0;
}
