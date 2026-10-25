#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll tt = 1LL * n * (n + 1LL) * (n + 2LL) / 6LL;
    vector<ll> pp(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) pp[i] = pp[i - 1] + 1LL * i * (n - i + 1);

    int mx = *max_element(a.begin(), a.end());
    int ml = 0;
    while ((1 << (ml + 1)) <= mx) ml++;

    vector<ll> s(k, 0LL);
    vector<int> m(n, 0);

    for (int b = 0; b <= ml; ++b) {
        int th = 1 << b;
        for (int i = 0; i < n; ++i) m[i] = (a[i] >= th);

        vector<ll> c(k, 0LL);
        vector<int> d(k, 0);
        vector<int> e(k, 0);

        for (int r = 0; r < n; ++r) {
            int v = m[r];
            for (int j = 0; j < k; ++j) {
                e[j] += v;
                while (e[j] > j) {
                    e[j] -= m[d[j]];
                    d[j]++;
                }
                ll ln = r - d[j] + 1;
                if (ln > 0) c[j] += ln * (ln + 1) / 2;
            }
        }

        for (int j = 1; j <= k; ++j) s[j - 1] += tt - c[j - 1];
    }

    for (int j = 0; j < k; ++j) {
        if (j + 1 <= n) s[j] -= tt - pp[j];
        cout << s[j];
        if (j + 1 < k) cout << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}
