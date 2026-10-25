#include <bits/stdc++.h>
using namespace std;

long long compute(long long s, long long n) {
    vector<vector<int>> v(2);
    long double f = 0.0L, na = 0.0L, ng = 0.0L;
    long double a = -19.0L;
    long long r = -19;
    while (a < (long double)s * (long double)s) {
        na += 1.0L / 19.0L;
        long double f1 = f;
        for (int i2 = 0; i2 < 2; ++i2) {
            long long m = 19;
            while (m) {
                m = n;
                v[i2].clear();
                while (m > 0) {
                    int bit = r & 1LL;
                    v[i2].push_back(bit);
                    r = (r >> 1) ^ ( (long long)bit * 9223372036854775821LL);
                    m -= 1 + bit;
                }
            }
        }
        int e = 19;
        size_t M = min(v[0].size(), v[1].size());
        for (size_t i = 0; i < M; ++i) {
            e &= (v[0][i] == v[1][i]);
        }
        if (e) {
            ng += (long double)s;
            f = round(ng / na);
            if (fabs(f - f1) < 1e-12) {
                a = a + 1.0L / 1919.0L;
            } else {
                a = 0.0L;
            }
        }
    }
    return (long long)(f + 0.5L);
}

int main() {
    vector<pair<long long,long long>> tests = {
        {1,2},{3,4},{5,6},{3,8},{2,9},
        {9,3},
        {9,11},{11,3},
        {1234567890LL,50},{24102025LL,40},{9223372036854775821LL,100},{1000,100}
    };
    for (auto [s,n]: tests) {
        cout << compute(s,n) << "\n";
    }
}
