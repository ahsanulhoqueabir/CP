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

const int MOD = 998244353;
const int G = 3;

int modpow(int a, long long e)
{
    int r = 1;
    while (e)
    {
        if (e & 1) r = (long long)r * a % MOD;
        a = (long long)a * a % MOD;
        e >>= 1;
    }
    return r;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

void ntt(vector<int> &a, bool invert)
{
    int n = (int)a.size();
    static vector<int> rev;
    static vector<int> roots{0, 1};
    if ((int)rev.size() != n)
    {
        rev.assign(n, 0);
        if (n > 1)
        {
            int lg = __builtin_ctz(n);
            for (int i = 0; i < n; ++i)
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
        }
    }
    if ((int)roots.size() < n)
    {
        int k = __builtin_ctz((int)roots.size());
        roots.resize(n);
        while ((1 << k) < n)
        {
            int z = modpow(G, (MOD - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i)
            {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = (long long)roots[i] * z % MOD;
            }
            ++k;
        }
    }
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int len = 1; len < n; len <<= 1)
    {
        for (int i = 0; i < n; i += len << 1)
        {
            for (int j = 0; j < len; ++j)
            {
                int u = a[i + j];
                int v = (long long)a[i + j + len] * roots[len + j] % MOD;
                int x = u + v;
                if (x >= MOD) x -= MOD;
                int y = u - v;
                if (y < 0) y += MOD;
                a[i + j] = x;
                a[i + j + len] = y;
            }
        }
    }
    if (invert)
    {
        reverse(a.begin() + 1, a.end());
        int inv_n = modinv(n);
        for (int &x : a) x = (long long)x * inv_n % MOD;
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    if (a.empty() || b.empty()) return {};
    int need = (int)a.size() + (int)b.size() - 1;
    int n = 1;
    while (n < need) n <<= 1;
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);
    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; ++i) fa[i] = (long long)fa[i] * fb[i] % MOD;
    ntt(fa, true);
    fa.resize(need);
    return fa;
}

void trim(vector<int> &a)
{
    while (!a.empty() && a.back() == 0) a.pop_back();
}

vector<int> poly_inv(const vector<int> &a, int need)
{
    vector<int> res(1, modinv(a[0]));
    int cur = 1;
    while (cur < need)
    {
        cur <<= 1;
        vector<int> a_cut(min(cur, (int)a.size()));
        for (int i = 0; i < (int)a_cut.size(); ++i) a_cut[i] = a[i];
        vector<int> tmp = multiply(a_cut, res);
        tmp.resize(cur);
        for (int i = 0; i < cur; ++i)
        {
            tmp[i] = (MOD - tmp[i]) % MOD;
        }
        tmp[0] = (tmp[0] + 2) % MOD;
        vector<int> new_res = multiply(res, tmp);
        new_res.resize(cur);
        res.swap(new_res);
    }
    res.resize(need);
    return res;
}

vector<int> poly_mod(const vector<int> &a, const vector<int> &b)
{
    vector<int> res = a;
    trim(res);
    if (res.size() < b.size()) return res;
    int n = (int)res.size();
    int m = (int)b.size();
    int k = n - m + 1;
    vector<int> ra(k), rb(m);
    for (int i = 0; i < k; ++i) ra[i] = res[n - 1 - i];
    for (int i = 0; i < m; ++i) rb[i] = b[m - 1 - i];
    vector<int> inv_rb = poly_inv(rb, k);
    vector<int> q = multiply(ra, inv_rb);
    q.resize(k);
    reverse(q.begin(), q.end());
    vector<int> qb = multiply(b, q);
    qb.resize(n);
    for (int i = 0; i < n; ++i)
    {
        res[i] -= qb[i];
        if (res[i] < 0) res[i] += MOD;
    }
    trim(res);
    return res;
}

vector<int> build_poly_roots(const vector<int> &roots, int l, int r)
{
    if (l == r) return { (MOD - roots[l]) % MOD, 1 };
    int mid = (l + r) >> 1;
    vector<int> left = build_poly_roots(roots, l, mid);
    vector<int> right = build_poly_roots(roots, mid + 1, r);
    return multiply(left, right);
}

struct MultiEval
{
    int n;
    vector<int> points;
    vector<vector<int>> tree;
    MultiEval(const vector<int> &pts) : n((int)pts.size()), points(pts)
    {
        if (!n) return;
        tree.resize(n * 4);
        build(1, 0, n - 1);
    }
    void build(int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = { (MOD - points[l]) % MOD, 1 };
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        tree[node] = multiply(tree[node << 1], tree[node << 1 | 1]);
    }
    void evaluate(const vector<int> &poly, vector<int> &res)
    {
        res.assign(n, 0);
        if (!n) return;
        evaluate_dfs(1, 0, n - 1, poly, res);
    }
    void evaluate_dfs(int node, int l, int r, const vector<int> &poly, vector<int> &res)
    {
        if (poly.empty())
        {
            for (int i = l; i <= r; ++i) res[i] = 0;
            return;
        }
        if (l == r)
        {
            long long val = 0;
            for (int i = (int)poly.size() - 1; i >= 0; --i)
                val = (val * points[l] + poly[i]) % MOD;
            res[l] = (int)val;
            return;
        }
        vector<int> left = poly_mod(poly, tree[node << 1]);
        vector<int> right = poly_mod(poly, tree[node << 1 | 1]);
        int mid = (l + r) >> 1;
        evaluate_dfs(node << 1, l, mid, left, res);
        evaluate_dfs(node << 1 | 1, mid + 1, r, right, res);
    }
};

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> S(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> S[i];
        if (S[i] >= MOD) S[i] %= MOD;
    }
    vector<pair<int, int>> ops(m);
    for (int i = 0; i < m; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            if (x >= MOD) x %= MOD;
            ops[i] = {type, x};
        }
        else
        {
            ops[i] = {type, 0};
        }
    }
    int n_mod = n % MOD;
    int sumS = 0;
    for (int v : S)
    {
        sumS += v;
        if (sumS >= MOD) sumS -= MOD;
    }
    vector<int> roots = S;
    vector<int> poly = build_poly_roots(roots, 0, n - 1);
    vector<int> poly_der;
    poly_der.resize(poly.size() ? poly.size() - 1 : 0);
    for (int i = 1; i < (int)poly.size(); ++i)
        poly_der[i - 1] = (long long)poly[i] * i % MOD;
    struct State
    {
        int a, b, c, d, alphaIdx;
    };
    vector<State> states(m);
    vector<int> alphas;
    alphas.reserve(m);
    int a = 1, b = 0, c = 0, d = 1;
    for (int i = 0; i < m; ++i)
    {
        int type = ops[i].first;
        if (type == 1)
        {
            int x = ops[i].second;
            int na = (a + (long long)x * c) % MOD;
            int nb = (b + (long long)x * d) % MOD;
            a = na;
            b = nb;
        }
        else
        {
            swap(a, c);
            swap(b, d);
        }
        int idx = -1;
        if (c != 0)
        {
            int inv_c = modinv(c);
            int alpha = (MOD - d) % MOD;
            alpha = (long long)alpha * inv_c % MOD;
            idx = (int)alphas.size();
            alphas.push_back(alpha);
        }
        states[i] = {a, b, c, d, idx};
    }
    vector<int> poly_vals;
    vector<int> poly_der_vals;
    vector<int> inv_poly_vals;
    if (!alphas.empty())
    {
        MultiEval evaluator(alphas);
        evaluator.evaluate(poly, poly_vals);
        evaluator.evaluate(poly_der, poly_der_vals);
        inv_poly_vals.resize(alphas.size());
        for (size_t i = 0; i < alphas.size(); ++i)
            inv_poly_vals[i] = modinv(poly_vals[i]);
    }
    vector<int> answers(m);
    for (int i = 0; i < m; ++i)
    {
        int ca = states[i].a;
        int cb = states[i].b;
        int cc = states[i].c;
        int cd = states[i].d;
        if (cc == 0)
        {
            int inv_d = modinv(cd);
            int term1 = (long long)sumS * ca % MOD * inv_d % MOD;
            int term2 = (long long)n_mod * cb % MOD * inv_d % MOD;
            answers[i] = (term1 + term2) % MOD;
        }
        else
        {
            int inv_c = modinv(cc);
            int term1 = (long long)n_mod * ca % MOD * inv_c % MOD;
            int numerator = ((long long)ca * cd - (long long)cb * cc) % MOD;
            if (numerator < 0) numerator += MOD;
            int inv_c_sq = (long long)inv_c * inv_c % MOD;
            int idx = states[i].alphaIdx;
            int ratio = (long long)poly_der_vals[idx] * inv_poly_vals[idx] % MOD;
            int term2 = (long long)numerator * inv_c_sq % MOD * ratio % MOD;
            answers[i] = (term1 + term2) % MOD;
        }
    }
    for (int v : answers) cout << v << endl;
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
