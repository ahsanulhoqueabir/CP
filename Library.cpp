// Author : Ahsanul Hoque Abir
// ============================================================================
//  [U] Utilities      U1 IO/print/debug  U2 rng/hash  U3 binary search/misc
//  [M] Math           M1 Mint/power  M2 Comb  M3 gcd/extgcd/CRT  M4 Sieve/phi/mu
//                     M5 MillerRabin/Pollard  M6 PrimePi/floor_sum  M7 Matrix
//                     M8 Gauss/det/XorBasis  M9 NTT/FFT  M10 Lagrange/BSGS/root
//                     M11 BigInt  M12 Fib/base/misc formulas
//  [D] Data structs   D1 DSU  D2 Fenwick(1D/range)  D3 SegTree  D4 LazySeg  D5 SparseTable
//                     D6 PBDS  D7 Mo  D8 Trie/XorTrie  D9 LiChao/CHT  D10 Persistent segtree
//                     D12 2D prefix / histogram / difference arrays
//  [G] Graphs         G1 BFS/0-1/Dijkstra/BF/Floyd  G2 Topo/SCC/2SAT  G3 Bridges
//                     G4 Tree: LCA/Euler/diameter  G5 HLD  G6 Centroid  G7 MST
//                     G8 Flow Dinic/MCMF  G9 Matching HK/Hungarian  G10 Euler path
//  [S] Strings        S1 Z/prefix/KMP  S2 Hash  S3 Manacher  S4 SuffixArray
//                     S5 AhoCorasick  S6 SuffixAutomaton  S7 minRotation/Lyndon
//  [P] DP             P1 LIS/LCS/Edit  P2 Knapsack  P3 Bitmask/SOS/TSP  P4 DigitDP
//                     P5 D&C opt  P6 Kadane/inversions/misc
//  [Y] Geometry       Y1 Point/hull/area/segments  Y2 closest pair  Y3 circle
//  [A] Games/Interactive  A1 interactive IO  A2 Grundy/nim/minimax  A3 patterns
//  [Z] Cheat sheet (limits, formulas, pitfalls)
// ============================================================================
#include <bits/stdc++.h>
#ifndef NO_PBDS  // old MinGW lacks some pb_ds headers: compile with -DNO_PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif
using namespace std;
#ifndef NO_PBDS
using namespace __gnu_pbds;
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)

constexpr int MOD = 1'000'000'007;
constexpr int MOD2 = 998'244'353;
constexpr ll INF = 4e18;
constexpr int INF32 = 1e9;
constexpr double EPS = 1e-9;
const double PI = acos(-1.0);

// ============================================================================
// [U1] IO / print / debug
// ============================================================================
template <class A, class B> istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template <class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <class A, class B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) { for (int i = 0; i < sz(v); i++) os << (i ? " " : "") << v[i]; return os; }
template <class T> void pv(const vector<T> &v, const char *sep = " ") { for (int i = 0; i < sz(v); i++) cout << (i ? sep : "") << v[i]; cout << endl; }
#ifdef __SIZEOF_INT128__
using i128 = __int128;
using u128 = unsigned __int128;
ostream &operator<<(ostream &os, i128 x) { if (x < 0) { os << '-'; x = -x; } string s; do { s += char('0' + (int)(x % 10)); x /= 10; } while (x); reverse(all(s)); return os << s; }
#endif
#define flush_out cout << flush
#ifdef LOCAL
template <class T> void _dbg(const T &x) { cerr << x << '\n'; }
template <class T, class... A> void _dbg(const T &x, const A &...a) { cerr << x << " | "; _dbg(a...); }
#define dbg(...) (cerr << "[" << #__VA_ARGS__ << "] = ", _dbg(__VA_ARGS__))
#else
#define dbg(...)
#endif
// Fast input when cin is too slow (rarely needed with sync_with_stdio(false)):
// static char _buf[1 << 25]; read whole stdin: fread(_buf,1,sizeof _buf,stdin);

// ============================================================================
// [U2] RNG / custom hash (anti-hack unordered_map) / timer
// ============================================================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t F = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + F); }
    size_t operator()(pair<int, int> p) const { return (*this)(((uint64_t)p.first << 32) ^ (uint32_t)p.second); }
};
// unordered_map<ll,int,custom_hash> mp;  mp.reserve(1<<20);
// gp_hash_table<ll,int,custom_hash> gp;   (faster, from pb_ds)
struct Timer { chrono::steady_clock::time_point t0 = chrono::steady_clock::now(); double ms() const { return chrono::duration<double, milli>(chrono::steady_clock::now() - t0).count(); } };

// ============================================================================
// [U3] Binary search / ternary / compress / misc small helpers
// ============================================================================
// first x in [lo,hi] with pred(x) true (pred monotone F..F T..T); returns hi+1 if none
template <class F> ll bsearch_first(ll lo, ll hi, F pred) { while (lo <= hi) { ll m = lo + (hi - lo) / 2; if (pred(m)) hi = m - 1; else lo = m + 1; } return lo; }
// last x in [lo,hi] with pred(x) true (pred T..T F..F); returns lo-1 if none
template <class F> ll bsearch_last(ll lo, ll hi, F pred) { while (lo <= hi) { ll m = lo + (hi - lo) / 2; if (pred(m)) lo = m + 1; else hi = m - 1; } return hi; }
// real-valued: minimise unimodal f on [l,r]
template <class F> double ternary_min(double l, double r, F f, int it = 100) { while (it--) { double a = l + (r - l) / 3, b = r - (r - l) / 3; if (f(a) < f(b)) r = b; else l = a; } return (l + r) / 2; }
// integer ternary (strictly unimodal): min of f on [l,r]
// coordinate compression
template <class T> struct Compress {
    vector<T> v;
    Compress() {}
    Compress(vector<T> a) { build(a); }
    void build(vector<T> a) { v = a; sort(all(v)); v.erase(unique(all(v)), v.end()); }
    int id(const T &x) const { return lower_bound(all(v), x) - v.begin(); }  // 0-indexed rank
    int size() const { return v.size(); }
};
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
inline bool inb(int x, int y, int n, int m) { return x >= 0 && y >= 0 && x < n && y < m; }
vector<string> splitStr(const string &s, char d) { vector<string> r; string c; for (char ch : s) { if (ch == d) { r.pb(c); c.clear(); } else c += ch; } r.pb(c); return r; }
template <class T> T ceil_div(T a, T b) { return a / b + ((a % b != 0) && ((a < 0) == (b < 0))); }   // ceil(a/b), b!=0
template <class T> T floor_div(T a, T b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); }
template <class T> bool chmin(T &a, const T &b) { return b < a ? (a = b, true) : false; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? (a = b, true) : false; }
int msb(ull x) { return 63 - __builtin_clzll(x); }          // floor(log2 x), x>0
ll isqrt(ll n) { ll r = sqrtl(n); while (r * r > n) r--; while ((r + 1) * (r + 1) <= n) r++; return r; }
// next greater element index (or n); use `<` variants by flipping comparator
vector<int> nextGreater(const vector<ll> &a) { int n = a.size(); vector<int> r(n, n); stack<int> st; for (int i = 0; i < n; i++) { while (!st.empty() && a[st.top()] < a[i]) { r[st.top()] = i; st.pop(); } st.push(i); } return r; }
// sliding window minimum of width k: res[i] = min(a[i..i+k-1])
vector<ll> slidingMin(const vector<ll> &a, int k) { deque<int> q; vector<ll> r; for (int i = 0; i < sz(a); i++) { while (!q.empty() && a[q.back()] >= a[i]) q.pop_back(); q.push_back(i); if (q.front() <= i - k) q.pop_front(); if (i >= k - 1) r.pb(a[q.front()]); } return r; }

// ============================================================================
// [M1] Modular arithmetic: power, mulmod, Mint
// ============================================================================
ull mulmod(ull a, ull b, ull m) {  // safe for m < 2^63 (works w/o __int128 too)
#ifdef __SIZEOF_INT128__
    return (u128)a * b % m;
#else
    ull q = (ull)((ld)a * b / m);
    ll r = (ll)(a * b - q * m);
    r %= (ll)m;
    if (r < 0) r += m;
    return r;
#endif
}
ull powmod64(ull b, ull e, ull m) { ull r = 1 % m; b %= m; while (e) { if (e & 1) r = mulmod(r, b, m); b = mulmod(b, b, m); e >>= 1; } return r; }
ll power(ll b, ll e, ll m = MOD) { ll r = 1 % m; b %= m; if (b < 0) b += m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }  // m <= 3e9
template <int M> struct Mint {
    int v;
    Mint(ll x = 0) { x %= M; if (x < 0) x += M; v = (int)x; }
    Mint &operator+=(const Mint &o) { v += o.v; if (v >= M) v -= M; return *this; }
    Mint &operator-=(const Mint &o) { v -= o.v; if (v < 0) v += M; return *this; }
    Mint &operator*=(const Mint &o) { v = (int)((ll)v * o.v % M); return *this; }
    Mint &operator/=(const Mint &o) { return *this *= o.inv(); }  // M prime
    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
    Mint operator-() const { return Mint(-(ll)v); }
    Mint pow(ll e) const { Mint r(1), b(*this); if (e < 0) { b = b.inv(); e = -e; } while (e) { if (e & 1) r *= b; b *= b; e >>= 1; } return r; }
    Mint inv() const { return pow(M - 2); }
    bool operator==(const Mint &o) const { return v == o.v; }
    bool operator!=(const Mint &o) const { return v != o.v; }
    friend ostream &operator<<(ostream &os, const Mint &a) { return os << a.v; }
    friend istream &operator>>(istream &is, Mint &a) { ll x; is >> x; a = Mint(x); return is; }
};
using mint = Mint<MOD>;
using mint9 = Mint<MOD2>;

// ============================================================================
// [M2] Combinatorics (factorials mod p).  Comb C(N); C.nCr(n,k)
// ============================================================================
struct Comb {
    vector<mint> f, fi;
    Comb(int n = 1000000) : f(n + 1), fi(n + 1) {
        f[0] = 1; for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;
        fi[n] = f[n].inv(); for (int i = n; i > 0; i--) fi[i - 1] = fi[i] * i;
    }
    mint nCr(int n, int r) const { return (r < 0 || r > n || n < 0) ? mint(0) : f[n] * fi[r] * fi[n - r]; }
    mint nPr(int n, int r) const { return (r < 0 || r > n) ? mint(0) : f[n] * fi[n - r]; }
    mint catalan(int n) const { return nCr(2 * n, n) - nCr(2 * n, n + 1); }
    mint starsBars(int n, int k) const { return nCr(n + k - 1, k - 1); }  // n identical into k bins (>=0)
    mint inv(int n) const { return fi[n] * f[n - 1]; }
};
// Pascal triangle small (no mod problem): ll C[61][61]; C[i][0]=1; C[i][j]=C[i-1][j-1]+C[i-1][j]

// ============================================================================
// [M3] gcd / lcm / extgcd / modinv / CRT / linear congruence
// ============================================================================
ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : llabs(a); }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }
ll extgcd(ll a, ll b, ll &x, ll &y) { if (!b) { x = 1; y = 0; return a; } ll g = extgcd(b, a % b, y, x); y -= a / b * x; return g; }
ll modinv(ll a, ll m) { ll x, y; ll g = extgcd(((a % m) + m) % m, m, x, y); if (g != 1) return -1; return (x % m + m) % m; }  // any m, gcd=1
// x = a1 (mod m1), x = a2 (mod m2)  ->  {x mod lcm, lcm}  or {-1,-1}
pll crt(ll a1, ll m1, ll a2, ll m2) {
    a1 = ((a1 % m1) + m1) % m1; a2 = ((a2 % m2) + m2) % m2;
    ll x, y, g = extgcd(m1, m2, x, y);
    if ((a2 - a1) % g) return {-1, -1};
    ll m2g = m2 / g, l = m1 / g * m2;
    ll d = (((a2 - a1) / g) % m2g + m2g) % m2g, xx = ((x % m2g) + m2g) % m2g;
    ll k = (ll)mulmod(d, xx, m2g);
    return {(a1 + m1 * k) % l, l};
}
// solve a*x = b (mod m): smallest nonneg x or -1
ll solveLinCong(ll a, ll b, ll m) { ll x, y, g = extgcd(((a % m) + m) % m, m, x, y); b = ((b % m) + m) % m; if (b % g) return -1; ll m2 = m / g; return (x % m2 + m2) % m2 * (b / g % m2) % m2; }

// ============================================================================
// [M4] Linear sieve: spf, primes, phi, mu.  Sieve S(N)
// ============================================================================
struct Sieve {
    int n; vector<int> spf, primes, phi, mu;
    Sieve(int n) : n(n), spf(n + 1, 0), phi(n + 1, 0), mu(n + 1, 0) {
        phi[1] = mu[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!spf[i]) { spf[i] = i; primes.pb(i); phi[i] = i - 1; mu[i] = -1; }
            for (int p : primes) {
                if (p > spf[i] || (ll)i * p > n) break;
                spf[i * p] = p;
                if (i % p == 0) { phi[i * p] = phi[i] * p; mu[i * p] = 0; }
                else { phi[i * p] = phi[i] * (p - 1); mu[i * p] = -mu[i]; }
            }
        }
    }
    bool isPrime(int x) const { return x >= 2 && spf[x] == x; }
    vector<pii> factorize(int x) const { vector<pii> r; while (x > 1) { int p = spf[x], c = 0; while (x % p == 0) x /= p, c++; r.pb({p, c}); } return r; }
    vector<int> divisors(int x) const { vector<int> d = {1}; for (pii f : factorize(x)) { int p = f.first, c = f.second, s = d.size(), pp = 1; for (int k = 1; k <= c; k++) { pp *= p; for (int i = 0; i < s; i++) d.pb(d[i] * pp); } } sort(all(d)); return d; }
};
vector<char> simpleSieve(int n) { vector<char> is(n + 1, 1); is[0] = 0; if (n >= 1) is[1] = 0; for (ll i = 2; i * i <= n; i++) if (is[i]) for (ll j = i * i; j <= n; j += i) is[j] = 0; return is; }
// segmented sieve on [L,R] (R up to 1e12, R-L <= 1e7); primes<=sqrt(R) from simple sieve
vector<ll> segSieve(ll L, ll R) {
    ll lim = isqrt(R); auto sp = simpleSieve((int)lim); vector<char> is(R - L + 1, 1);
    for (ll p = 2; p <= lim; p++) if (sp[p]) for (ll j = max(p * p, (L + p - 1) / p * p); j <= R; j += p) is[j - L] = 0;
    vector<ll> r; for (ll i = max(L, 2LL); i <= R; i++) if (is[i - L]) r.pb(i); return r;
}
vector<pll> factorTrial(ll n) { vector<pll> r; for (ll p = 2; p * p <= n; p++) if (n % p == 0) { int c = 0; while (n % p == 0) n /= p, c++; r.pb({p, c}); } if (n > 1) r.pb({n, 1}); return r; }
vector<ll> divisorsTrial(ll n) { vector<ll> d; for (ll i = 1; i * i <= n; i++) if (n % i == 0) { d.pb(i); if (i != n / i) d.pb(n / i); } sort(all(d)); return d; }
ll phiOf(ll n) { ll r = n; for (ll p = 2; p * p <= n; p++) if (n % p == 0) { while (n % p == 0) n /= p; r -= r / p; } if (n > 1) r -= r / n; return r; }
// sum of divisors sigma / count tau via factorization; number of d in [1..n] coprime to m: inclusion-exclusion over primes of m
// Divisor-sum trick: for i in 1..n: for j=i;j<=n;j+=i -> O(n log n) (counts divisors of all numbers)

// ============================================================================
// [M5] Miller-Rabin (64-bit deterministic) + Pollard rho factorization
// ============================================================================
bool isPrime64(ull n) {
    if (n < 2) return false;
    for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) { if (n % p == 0) return n == p; }
    ull d = n - 1; int s = 0; while (!(d & 1)) d >>= 1, s++;
    for (ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        ull x = powmod64(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) { x = mulmod(x, x, n); if (x == n - 1) { comp = false; break; } }
        if (comp) return false;
    }
    return true;
}
ull pollardRho(ull n) {
    if (n % 2 == 0) return 2;
    while (true) {
        ull c = rng() % (n - 1) + 1, x = rng() % n, y = x, d = 1;
        auto f = [&](ull v) { return (mulmod(v, v, n) + c) % n; };
        while (d == 1) { x = f(x); y = f(f(y)); d = __gcd(x > y ? x - y : y - x, n); }
        if (d != n) return d;
    }
}
void factorRec(ull n, vector<ull> &r) {
    if (n == 1) return;
    if (isPrime64(n)) { r.pb(n); return; }
    for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) if (n % p == 0) { r.pb(p); factorRec(n / p, r); return; }
    ull d = pollardRho(n); factorRec(d, r); factorRec(n / d, r);
}
vector<ull> factor64(ull n) { vector<ull> r; factorRec(n, r); sort(all(r)); return r; }  // prime factors with multiplicity, sorted

// ============================================================================
// [M6] pi(n) (Lucy_Hedgehog, n up to ~1e11), floor_sum, misc number theory
// ============================================================================
ll primePi(ll n) {
    if (n < 2) return 0;
    ll r = isqrt(n); vector<ll> lo(r + 2), hi(r + 2);
    for (ll i = 1; i <= r; i++) { lo[i] = i - 1; hi[i] = n / i - 1; }
    for (ll p = 2; p <= r; p++) {
        if (lo[p] == lo[p - 1]) continue;
        ll pc = lo[p - 1], p2 = p * p, end = min(r, n / p2);
        for (ll i = 1; i <= end; i++) { ll d = i * p; hi[i] -= (d <= r ? hi[d] : lo[n / d]) - pc; }
        for (ll i = r; i >= p2; i--) lo[i] -= lo[i / p] - pc;
    }
    return hi[1];
}
// sum_{i=0}^{n-1} floor((a*i+b)/m)   (n,m >= 1, a,b >= 0)
ull floor_sum(ull n, ull m, ull a, ull b) {
    ull ans = 0;
    while (true) {
        if (a >= m) { ans += n * (n - 1) / 2 * (a / m); a %= m; }
        if (b >= m) { ans += n * (b / m); b %= m; }
        ull y = a * n + b; if (y < m) break;
        n = y / m; b = y % m; swap(m, a);
    }
    return ans;
}
// primitive root of prime p
ll primitiveRoot(ll p) {
    if (p == 2) return 1;
    vector<ll> fs; ll ph = p - 1, t = ph; for (ll i = 2; i * i <= t; i++) if (t % i == 0) { fs.pb(i); while (t % i == 0) t /= i; } if (t > 1) fs.pb(t);
    for (ll g = 2; g < p; g++) { bool ok = true; for (ll f : fs) if (power(g, ph / f, p) == 1) { ok = false; break; } if (ok) return g; }
    return -1;
}
// smallest x>=0 with a^x = b (mod m), gcd(a,m)=1 (for general m use extended BSGS); -1 if none
ll bsgs(ll a, ll b, ll m) {
    a %= m; b %= m; if (m == 1) return 0;
    ll n = (ll)sqrtl(m) + 1; unordered_map<ll, ll> mp; ll cur = b;
    for (ll j = 0; j <= n; j++) { mp[cur] = j; cur = cur * a % m; }
    ll an = power(a, n, m); cur = 1;
    for (ll i = 1; i <= n; i++) { cur = cur * an % m; auto it = mp.find(cur); if (it != mp.end()) return i * n - it->second; }
    return -1;
}

// ============================================================================
// [M7] Matrix (generic T: mint / ll / double).  Mat<mint> A(n,n); A.pow(e)
// ============================================================================
template <class T> struct Mat {
    int n, m; vector<vector<T>> a;
    Mat(int n = 0, int m = 0) : n(n), m(m), a(n, vector<T>(m, T(0))) {}
    static Mat I(int n) { Mat r(n, n); for (int i = 0; i < n; i++) r.a[i][i] = T(1); return r; }
    Mat operator*(const Mat &o) const {
        Mat r(n, o.m);
        for (int i = 0; i < n; i++) for (int k = 0; k < m; k++) { if (a[i][k] == T(0)) continue; for (int j = 0; j < o.m; j++) r.a[i][j] += a[i][k] * o.a[k][j]; }
        return r;
    }
    Mat pow(ll e) const { Mat r = I(n), b = *this; while (e) { if (e & 1) r = r * b; b = b * b; e >>= 1; } return r; }
};
// Linear recurrence f(n)=c1 f(n-1)+...+ck f(n-k): build k x k companion matrix, pow(n-k+1), multiply by init vector.
// Counting walks of length L in graph = adjacency^L.

// ============================================================================
// [M8] Gauss: mod p solve/rank/det, double det, XOR basis
// ============================================================================
// augmented a: n x (m+1). Returns rank, x = a solution (free vars = 0); returns -1 if inconsistent
int gaussSolve(vector<vector<mint>> a, vector<mint> &x) {
    int n = a.size(), m = a[0].size() - 1, row = 0; vector<int> where(m, -1);
    for (int col = 0; col < m && row < n; col++) {
        int sel = -1; for (int i = row; i < n; i++) if (a[i][col].v) { sel = i; break; }
        if (sel < 0) continue;
        swap(a[sel], a[row]); where[col] = row;
        mint iv = a[row][col].inv(); for (int j = col; j <= m; j++) a[row][j] *= iv;
        for (int i = 0; i < n; i++) if (i != row && a[i][col].v) { mint f = a[i][col]; for (int j = col; j <= m; j++) a[i][j] -= f * a[row][j]; }
        row++;
    }
    for (int i = row; i < n; i++) if (a[i][m].v) return -1;
    x.assign(m, 0); for (int c = 0; c < m; c++) if (where[c] != -1) x[c] = a[where[c]][m];
    return row;
}
mint detMod(vector<vector<mint>> a) {  // square matrix mod prime
    int n = a.size(); mint d = 1;
    for (int c = 0; c < n; c++) {
        int p = -1; for (int i = c; i < n; i++) if (a[i][c].v) { p = i; break; }
        if (p < 0) return 0;
        if (p != c) { swap(a[p], a[c]); d = -d; }
        d *= a[c][c]; mint iv = a[c][c].inv();
        for (int i = c + 1; i < n; i++) if (a[i][c].v) { mint f = a[i][c] * iv; for (int j = c; j < n; j++) a[i][j] -= f * a[c][j]; }
    }
    return d;
}
// XOR (GF(2)) linear basis for up to 63 bits
struct XorBasis {
    ull b[64]; int cnt = 0;
    XorBasis() { memset(b, 0, sizeof b); }
    bool insert(ull x) { for (int i = 63; i >= 0; i--) { if (!(x >> i & 1)) continue; if (!b[i]) { b[i] = x; cnt++; return true; } x ^= b[i]; } return false; }
    bool contains(ull x) const { for (int i = 63; i >= 0; i--) { if (!(x >> i & 1)) continue; if (!b[i]) return false; x ^= b[i]; } return true; }
    ull maxXor(ull x = 0) const { for (int i = 63; i >= 0; i--) if (b[i] && (x ^ b[i]) > x) x ^= b[i]; return x; }
    ull minXor(ull x) const { for (int i = 63; i >= 0; i--) if (b[i] && (x >> i & 1)) x ^= b[i]; return x; }
};

// ============================================================================
// [M9] NTT (mod 998244353) + FFT (double) convolution
// ============================================================================
void ntt(vector<mint9> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) { int bit = n >> 1; for (; j & bit; bit >>= 1) j ^= bit; j ^= bit; if (i < j) swap(a[i], a[j]); }
    for (int len = 2; len <= n; len <<= 1) {
        mint9 w = mint9(3).pow((MOD2 - 1) / len); if (invert) w = w.inv();
        for (int i = 0; i < n; i += len) { mint9 wn = 1; for (int j = 0; j < len / 2; j++) { mint9 u = a[i + j], v = a[i + j + len / 2] * wn; a[i + j] = u + v; a[i + j + len / 2] = u - v; wn *= w; } }
    }
    if (invert) { mint9 ni = mint9(n).inv(); for (auto &x : a) x *= ni; }
}
vector<mint9> multiply(vector<mint9> a, vector<mint9> b) {
    if (a.empty() || b.empty()) return {};
    int need = a.size() + b.size() - 1, n = 1; while (n < need) n <<= 1;
    a.resize(n); b.resize(n); ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a, true); a.resize(need); return a;
}
// FFT with doubles: exact if result coefficients < ~1e14 / careful with big values
void fft(vector<complex<double>> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) { int bit = n >> 1; for (; j & bit; bit >>= 1) j ^= bit; j ^= bit; if (i < j) swap(a[i], a[j]); }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1); complex<double> wl(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) { complex<double> w(1); for (int j = 0; j < len / 2; j++) { auto u = a[i + j], v = a[i + j + len / 2] * w; a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wl; } }
    }
    if (invert) for (auto &x : a) x /= n;
}
vector<ll> multiplyFFT(const vector<ll> &a, const vector<ll> &b) {
    if (a.empty() || b.empty()) return {};
    vector<complex<double>> fa(all(a)), fb(all(b)); int need = a.size() + b.size() - 1, n = 1; while (n < need) n <<= 1;
    fa.resize(n); fb.resize(n); fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true); vector<ll> r(need); for (int i = 0; i < need; i++) r[i] = llround(fa[i].real()); return r;
}
// Use cases: string matching with wildcards, counting pair sums (a[i]+b[j]=k), big-number multiplication, subset-sum counts.

// ============================================================================
// [M10] Lagrange interpolation (points 0..n), mod prime
// ============================================================================
mint lagrange(const vector<mint> &y, ll x) {  // y[i]=f(i), deg f <= n=y.size()-1, evaluate f(x)
    int n = y.size() - 1; if (x <= n) return y[x];
    vector<mint> pre(n + 2, 1), suf(n + 2, 1), fct(n + 1, 1);
    for (int i = 0; i <= n; i++) pre[i + 1] = pre[i] * mint(x - i);
    for (int i = n; i >= 0; i--) suf[i] = suf[i + 1] * mint(x - i);
    for (int i = 1; i <= n; i++) fct[i] = fct[i - 1] * i;
    mint res = 0;
    for (int i = 0; i <= n; i++) { mint t = y[i] * pre[i] * suf[i + 1] / (fct[i] * fct[n - i]); res += ((n - i) & 1) ? -t : t; }
    return res;
}
// Sum of i^k for i=1..n: polynomial of degree k+1 -> compute k+2 values, lagrange.

// ============================================================================
// [M11] BigInt (non-negative, base 1e9). a+b, a-b (a>=b), a*b, a*small, a/small, cmp
// ============================================================================
struct BigInt {
    static const int B = 1000000000;
    vector<int> d;  // little endian; zero = empty
    BigInt(ll x = 0) { while (x > 0) { d.pb(x % B); x /= B; } }
    BigInt(const string &s) { for (int i = s.size(); i > 0; i -= 9) { int l = max(0, i - 9); d.pb(stoi(s.substr(l, i - l))); } trim(); }
    void trim() { while (!d.empty() && d.back() == 0) d.pop_back(); }
    bool isZero() const { return d.empty(); }
    string str() const { if (d.empty()) return "0"; string s = to_string(d.back()); char buf[16]; for (int i = (int)d.size() - 2; i >= 0; i--) { snprintf(buf, sizeof buf, "%09d", d[i]); s += buf; } return s; }
    friend bool operator<(const BigInt &a, const BigInt &b) { if (a.d.size() != b.d.size()) return a.d.size() < b.d.size(); for (int i = (int)a.d.size() - 1; i >= 0; i--) if (a.d[i] != b.d[i]) return a.d[i] < b.d[i]; return false; }
    friend bool operator==(const BigInt &a, const BigInt &b) { return a.d == b.d; }
    friend BigInt operator+(const BigInt &a, const BigInt &b) {
        BigInt r; int c = 0; for (size_t i = 0; i < max(a.d.size(), b.d.size()) || c; i++) { ll s = c + (i < a.d.size() ? a.d[i] : 0) + (i < b.d.size() ? b.d[i] : 0); r.d.pb(s % B); c = s / B; } return r;
    }
    friend BigInt operator-(const BigInt &a, const BigInt &b) {
        BigInt r = a; int c = 0; for (size_t i = 0; i < r.d.size() || c; i++) { ll s = (ll)r.d[i] - c - (i < b.d.size() ? b.d[i] : 0); c = s < 0; if (c) s += B; r.d[i] = (int)s; } r.trim(); return r;
    }
    friend BigInt operator*(const BigInt &a, const BigInt &b) {
        if (a.isZero() || b.isZero()) return BigInt(); vector<ull> t(a.d.size() + b.d.size() + 1, 0);
        for (size_t i = 0; i < a.d.size(); i++) { ull c = 0; for (size_t j = 0; j < b.d.size() || c; j++) { ull cur = t[i + j] + c + (j < b.d.size() ? (ull)a.d[i] * b.d[j] : 0); t[i + j] = cur % B; c = cur / B; } }
        BigInt r; for (auto x : t) r.d.pb((int)x); r.trim(); return r;
    }
    BigInt mulSmall(ll m) const { BigInt r; ull c = 0; for (size_t i = 0; i < d.size() || c; i++) { ull cur = c + (i < d.size() ? (ull)d[i] * m : 0); r.d.pb(cur % B); c = cur / B; } r.trim(); return r; }  // m < ~1.8e10
    BigInt divSmall(ll m, ll &rem) const { BigInt r; r.d.resize(d.size()); ll c = 0; for (int i = (int)d.size() - 1; i >= 0; i--) { ll cur = d[i] + c * B; r.d[i] = (int)(cur / m); c = cur % m; } rem = c; r.trim(); return r; }
};
// BigInt factorial: BigInt f(1); for i in 2..n f = f.mulSmall(i);   (Python-style big ints are rare; Java BigInteger alt.)

// ============================================================================
// [M12] Fibonacci fast doubling, base conversion, misc formulas
// ============================================================================
pair<mint, mint> fibPair(ll n) {  // returns (F(n), F(n+1))
    if (n == 0) return {0, 1};
    auto p = fibPair(n >> 1); mint a = p.first, b = p.second, c = a * (b * 2 - a), d = a * a + b * b;
    return (n & 1) ? make_pair(d, c + d) : make_pair(c, d);
}
string toBase(ll n, int b) { if (n == 0) return "0"; bool neg = n < 0; if (neg) n = -n; string s; while (n) { int r = n % b; s += char(r < 10 ? '0' + r : 'A' + r - 10); n /= b; } if (neg) s += '-'; reverse(all(s)); return s; }
ll fromBase(const string &s, int b) { ll r = 0; for (char c : s) r = r * b + (isdigit(c) ? c - '0' : toupper(c) - 'A' + 10); return r; }
ll sumDigits(ll n) { ll s = 0; while (n) s += n % 10, n /= 10; return s; }
ll sumRange(ll l, ll r) { return (l + r) * (r - l + 1) / 2; }               // careful overflow: use i128/mint
ll sumSquares(ll n) { return n * (n + 1) * (2 * n + 1) / 6; }
ll sumCubes(ll n) { ll s = n * (n + 1) / 2; return s * s; }
// number of trailing zeros of n! in base 10: sum n/5^k.  Legendre: v_p(n!) = sum n/p^k
ll legendre(ll n, ll p) { ll r = 0; while (n) { n /= p; r += n; } return r; }
// Josephus (0-indexed survivor, step k): f(1)=0; f(i)=(f(i-1)+k)%i
ll josephus(ll n, ll k) { ll r = 0; for (ll i = 2; i <= n; i++) r = (r + k) % i; return r; }
// Derangements D(n)=(n-1)(D(n-1)+D(n-2)); Catalan; Bell; Stirling2 S(n,k)=k S(n-1,k)+S(n-1,k-1)

// ============================================================================
// [D1] DSU: plain, rollback (offline dynamic connectivity), weighted (potential)
// ============================================================================
struct DSU {
    vector<int> p, s; int comps;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n); iota(all(p), 0); s.assign(n, 1); comps = n; }
    int find(int x) { while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x; }
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; if (s[a] < s[b]) swap(a, b); p[b] = a; s[a] += s[b]; comps--; return true; }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return s[find(x)]; }
};
struct RollbackDSU {  // no path compression; undo in LIFO order
    vector<int> p, s; vector<pii> st;
    RollbackDSU(int n = 0) : p(n), s(n, 1) { iota(all(p), 0); }
    int find(int x) const { while (p[x] != x) x = p[x]; return x; }
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; if (s[a] < s[b]) swap(a, b); p[b] = a; s[a] += s[b]; st.pb({a, b}); return true; }
    int snapshot() const { return st.size(); }
    void rollback(int snap) { while ((int)st.size() > snap) { auto pr = st.back(); st.pop_back(); s[pr.first] -= s[pr.second]; p[pr.second] = pr.second; } }
};
struct WDSU {  // val[b]-val[a]=d constraints; w[x]=val[x]-val[parent]
    vector<int> p; vector<ll> w;
    WDSU(int n = 0) : p(n), w(n, 0) { iota(all(p), 0); }
    int find(int x) { if (p[x] == x) return x; int r = find(p[x]); w[x] += w[p[x]]; p[x] = r; return r; }
    bool unite(int a, int b, ll d) {  // returns false if contradicts existing info
        int ra = find(a), rb = find(b);
        if (ra == rb) return w[b] - w[a] == d;
        p[rb] = ra; w[rb] = d + w[a] - w[b]; return true;
    }
    ll diff(int a, int b) { find(a); find(b); return w[b] - w[a]; }  // only valid if same(a,b)
    bool same(int a, int b) { return find(a) == find(b); }
};

// ============================================================================
// [D2] Fenwick tree: point-add/prefix-sum, range-add/range-sum, 2D. 0-indexed, [l,r)
// ============================================================================
template <class T> struct BIT {
    int n; vector<T> t;
    BIT(int n = 0) : n(n), t(n + 1, T()) {}
    void add(int i, T v) { for (i++; i <= n; i += i & -i) t[i] += v; }
    T sum(int i) const { T s = T(); for (; i > 0; i -= i & -i) s += t[i]; return s; }           // sum of [0,i)
    T range(int l, int r) const { return sum(r) - sum(l); }
    int lower_bound(T k) const { if (n == 0) return 0; int pos = 0; for (int pw = 1 << (31 - __builtin_clz(n)); pw; pw >>= 1) if (pos + pw <= n && t[pos + pw] < k) { pos += pw; k -= t[pos]; } return pos; }  // smallest idx with prefix(idx+1)>=k (non-negative values)
};
template <class T> struct BITRange {  // range add, range sum
    BIT<T> a, b; BITRange(int n = 0) : a(n), b(n) {}
    void add(int l, int r, T v) { a.add(l, v); a.add(r, -v); b.add(l, v * l); b.add(r, -v * r); }
    T prefix(int i) const { return a.sum(i) * i - b.sum(i); }
    T range(int l, int r) const { return prefix(r) - prefix(l); }
};

// ============================================================================
// [D3] Iterative segment tree (any monoid, non-commutative safe). [l,r)
//   auto op=[](ll a,ll b){return a+b;};  SegTree<ll,decltype(op)> st(n,0,op);
//   (struct values: define identity e, e.g. pair/struct and op that merges)
// ============================================================================
template <class T, class F> struct SegTree {
    int n; T e; F op; vector<T> t;
    SegTree(int n, T e, F op) : n(n), e(e), op(op), t(2 * n, e) {}
    SegTree(const vector<T> &a, T e, F op) : n(a.size()), e(e), op(op), t(2 * a.size(), e) { for (int i = 0; i < n; i++) t[n + i] = a[i]; for (int i = n - 1; i > 0; i--) t[i] = op(t[2 * i], t[2 * i + 1]); }
    void set(int i, T v) { for (t[i += n] = v; i > 1; i >>= 1) t[i >> 1] = op(t[i & ~1], t[i | 1]); }
    T get(int i) const { return t[i + n]; }
    T query(int l, int r) const { T rl = e, rr = e; for (l += n, r += n; l < r; l >>= 1, r >>= 1) { if (l & 1) rl = op(rl, t[l++]); if (r & 1) rr = op(t[--r], rr); } return op(rl, rr); }
};

// ============================================================================
// [D4] Lazy segment tree (recursive, ACL-style). Define monoid S and map F:
//   S op(S,S); S e(); S mapping(F,S); F comp(F f,F g) /* f after g */; F id();
//   Example range-add/range-sum:  struct S{ll sum;int len;}; S op(S a,S b){return {a.sum+b.sum,a.len+b.len};}
//   S e(){return {0,0};} S mapping(ll f,S s){return {s.sum+f*s.len,s.len};} ll comp(ll f,ll g){return f+g;} ll id(){return 0;}
//   LazySeg<S,op,e,ll,mapping,comp,id> sg(vector<S>(n,{0,1}));  sg.update(l,r,v); sg.prod(l,r).sum
// ============================================================================
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*comp)(F, F), F (*id)()> struct LazySeg {
    int n; vector<S> d; vector<F> lz;
    LazySeg(int n = 0) : LazySeg(vector<S>(n, e())) {}
    LazySeg(const vector<S> &v) : n(v.size()), d(4 * max<size_t>(1, v.size()), e()), lz(4 * max<size_t>(1, v.size()), id()) { if (n) build(1, 0, n, v); }
    void build(int o, int lo, int hi, const vector<S> &v) { if (hi - lo == 1) { d[o] = v[lo]; return; } int m = (lo + hi) / 2; build(2 * o, lo, m, v); build(2 * o + 1, m, hi, v); d[o] = op(d[2 * o], d[2 * o + 1]); }
    void app(int o, F f) { d[o] = mapping(f, d[o]); lz[o] = comp(f, lz[o]); }
    void push(int o) { app(2 * o, lz[o]); app(2 * o + 1, lz[o]); lz[o] = id(); }
    void update(int l, int r, F f) { upd(1, 0, n, l, r, f); }
    void upd(int o, int lo, int hi, int l, int r, F f) {
        if (r <= lo || hi <= l) return;
        if (l <= lo && hi <= r) { app(o, f); return; }
        push(o); int m = (lo + hi) / 2; upd(2 * o, lo, m, l, r, f); upd(2 * o + 1, m, hi, l, r, f); d[o] = op(d[2 * o], d[2 * o + 1]);
    }
    S prod(int l, int r) { return qry(1, 0, n, l, r); }
    S qry(int o, int lo, int hi, int l, int r) {
        if (r <= lo || hi <= l) return e();
        if (l <= lo && hi <= r) return d[o];
        push(o); int m = (lo + hi) / 2; return op(qry(2 * o, lo, m, l, r), qry(2 * o + 1, m, hi, l, r));
    }
    S get(int i) { return prod(i, i + 1); }
    void set(int i, S x) { st(1, 0, n, i, x); }
    void st(int o, int lo, int hi, int i, S x) { if (hi - lo == 1) { d[o] = x; return; } push(o); int m = (lo + hi) / 2; if (i < m) st(2 * o, lo, m, i, x); else st(2 * o + 1, m, hi, i, x); d[o] = op(d[2 * o], d[2 * o + 1]); }
    // first position r>=l where g(op(a[l..r])) becomes false (g monotone, g(e())==true); returns n if never
    template <class G> int max_right(int l, G g) { S acc = e(); int r = mr(1, 0, n, l, g, acc); return r == -1 ? n : r; }
    template <class G> int mr(int o, int lo, int hi, int l, G &g, S &acc) {
        if (hi <= l) return -1;
        if (l <= lo) { S nx = op(acc, d[o]); if (g(nx)) { acc = nx; return -1; } if (hi - lo == 1) return lo; }
        push(o); int m = (lo + hi) / 2; int r = mr(2 * o, lo, m, l, g, acc); if (r != -1) return r; return mr(2 * o + 1, m, hi, l, g, acc);
    }
};

// ============================================================================
// [D5] Sparse table (idempotent op: min/max/gcd/and/or). Build O(n log n), query O(1) [l,r)
//   Sparse<int, function<int(int,int)>> sp(a, [](int x,int y){return min(x,y);});
// ============================================================================
template <class T, class F> struct Sparse {
    vector<vector<T>> t; F f;
    Sparse(const vector<T> &a, F f) : f(f) {
        int n = a.size(), K = 1; while ((1 << K) <= n) K++;
        t.assign(K, a);
        for (int k = 1; k < K; k++) for (int i = 0; i + (1 << k) <= n; i++) t[k][i] = f(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }
    T query(int l, int r) const { int k = 31 - __builtin_clz(r - l); return f(t[k][l], t[k][r - (1 << k)]); }
};

// ============================================================================
// [D6] PBDS: ordered set / multiset  (order_of_key, find_by_order)
//   oset<int> s; s.insert(x); s.order_of_key(x) = #elements < x; *s.find_by_order(k) = k-th (0-idx)
//   omset: erase one copy: s.erase(s.find_by_order(s.order_of_key(x)));  count of <=x : order_of_key(x+1)
// ============================================================================
#ifndef NO_PBDS
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
#endif

// ============================================================================
// [D7] Mo's algorithm. queries (l,r) inclusive 0-indexed. add(i), rem(i), rec(queryId)
// ============================================================================
template <class FA, class FR, class FG> void moRun(int n, const vector<pii> &q, FA add, FR rem, FG rec) {
    int Q = q.size(); if (!Q) return;
    int B = max(1, (int)(n / sqrt((double)Q))); vector<int> ord(Q); iota(all(ord), 0);
    sort(all(ord), [&](int a, int b) { int ba = q[a].first / B, bb = q[b].first / B; if (ba != bb) return ba < bb; return (ba & 1) ? q[a].second > q[b].second : q[a].second < q[b].second; });
    int cl = 0, cr = -1;
    for (int id : ord) { int l = q[id].first, r = q[id].second; while (cl > l) add(--cl); while (cr < r) add(++cr); while (cl < l) rem(cl++); while (cr > r) rem(cr--); rec(id); }
}

// ============================================================================
// [D8] Tries: string trie (26 letters) and binary XOR trie with counts
// ============================================================================
struct Trie {
    vector<array<int, 26>> nx; vector<int> pass, endc;
    Trie() { newNode(); }
    int newNode() { array<int, 26> a; a.fill(-1); nx.pb(a); pass.pb(0); endc.pb(0); return nx.size() - 1; }
    void insert(const string &s) { int u = 0; for (char c : s) { int k = c - 'a'; if (nx[u][k] < 0) { int v = newNode(); nx[u][k] = v; } u = nx[u][k]; pass[u]++; } endc[u]++; }
    int countPrefix(const string &s) const { int u = 0; for (char c : s) { u = nx[u][c - 'a']; if (u < 0) return 0; } return pass[u]; }
    bool contains(const string &s) const { int u = 0; for (char c : s) { u = nx[u][c - 'a']; if (u < 0) return false; } return endc[u] > 0; }
};
struct XorTrie {
    vector<array<int, 2>> ch; vector<int> cnt; int B;
    XorTrie(int B = 30) : B(B) { ch.pb({0, 0}); cnt.pb(0); }
    void insert(ll x, int d = 1) { int u = 0; for (int i = B - 1; i >= 0; i--) { int b = x >> i & 1; if (!ch[u][b]) { int v = ch.size(); ch[u][b] = v; ch.pb({0, 0}); cnt.pb(0); } u = ch[u][b]; cnt[u] += d; } }  // d=-1 erases
    ll maxXor(ll x) const { int u = 0; ll r = 0; for (int i = B - 1; i >= 0; i--) { int b = x >> i & 1, w = ch[u][b ^ 1]; if (w && cnt[w] > 0) { r |= 1LL << i; u = w; } else u = ch[u][b]; } return r; }  // trie must be non-empty
    ll minXor(ll x) const { int u = 0; ll r = 0; for (int i = B - 1; i >= 0; i--) { int b = x >> i & 1, w = ch[u][b]; if (w && cnt[w] > 0) u = w; else { r |= 1LL << i; u = ch[u][b ^ 1]; } } return r; }
    ll countLess(ll x, ll k) const { int u = 0; ll res = 0; for (int i = B - 1; i >= 0 && u >= 0; i--) { int b = x >> i & 1, kb = k >> i & 1; if (kb) { int w = ch[u][b]; if (w) res += cnt[w]; u = ch[u][b ^ 1]; } else u = ch[u][b]; if (!u) break; } return res; }  // #y in trie with (x^y) < k
};

// ============================================================================
// [D9] Li Chao tree (min of lines at integer x in [lo,hi]); for max, negate m,b and answer
// ============================================================================
struct LiChao {
    struct Line { ll m, b; ll eval(ll x) const { return m * x + b; } };
    struct Node { Line ln; int l, r; Node() : ln{0, (ll)4e18}, l(-1), r(-1) {} };
    vector<Node> t; ll lo, hi;
    LiChao(ll lo, ll hi) : lo(lo), hi(hi) { t.pb(Node()); }
    void add(ll m, ll b) { add(0, lo, hi, Line{m, b}); }
    void add(int o, ll l, ll r, Line nw) {
        ll m = l + (r - l) / 2;
        bool lef = nw.eval(l) < t[o].ln.eval(l), mid = nw.eval(m) < t[o].ln.eval(m);
        if (mid) swap(t[o].ln, nw);
        if (l == r) return;
        if (lef != mid) { if (t[o].l < 0) { t[o].l = t.size(); t.pb(Node()); } add(t[o].l, l, m, nw); }
        else { if (t[o].r < 0) { t[o].r = t.size(); t.pb(Node()); } add(t[o].r, m + 1, r, nw); }
    }
    ll query(ll x) const { int o = 0; ll l = lo, r = hi, res = 4e18; while (o >= 0) { res = min(res, t[o].ln.eval(x)); if (l == r) break; ll m = l + (r - l) / 2; if (x <= m) { o = t[o].l; r = m; } else { o = t[o].r; l = m + 1; } } return res; }
};

// ============================================================================
// [D10] Persistent segment tree: k-th smallest in a[l..r)  (values compressed to [0,n))
//   PST p(n); for x in a: p.push(x); p.kth(l,r,k) -> k-th (0-idx) smallest in a[l..r); p.cntLess(l,r,x)
// ============================================================================
struct PST {
    struct N { int l, r, c; };
    vector<N> t; vector<int> root; int n;
    PST(int n) : n(n) { t.pb({0, 0, 0}); root.pb(0); }
    int upd(int p, int lo, int hi, int pos) {
        int q = t.size(); t.pb(t[p]); t[q].c++;
        if (hi - lo > 1) { int m = (lo + hi) / 2; if (pos < m) { int x = upd(t[p].l, lo, m, pos); t[q].l = x; } else { int x = upd(t[p].r, m, hi, pos); t[q].r = x; } }
        return q;
    }
    void push(int pos) { int x = upd(root.back(), 0, n, pos); root.pb(x); }
    int kth(int l, int r, int k) const { int a = root[l], b = root[r], lo = 0, hi = n; while (hi - lo > 1) { int m = (lo + hi) / 2, c = t[t[b].l].c - t[t[a].l].c; if (k < c) { a = t[a].l; b = t[b].l; hi = m; } else { k -= c; a = t[a].r; b = t[b].r; lo = m; } } return lo; }
    int cntLess(int l, int r, int x) const {  // #values < x in a[l..r)
        int a = root[l], b = root[r]; if (x <= 0) return 0; if (x >= n) return t[b].c - t[a].c;
        int lo = 0, hi = n, res = 0;
        while (hi - lo > 1) { int m = (lo + hi) / 2; if (x <= m) { a = t[a].l; b = t[b].l; hi = m; } else { res += t[t[b].l].c - t[t[a].l].c; a = t[a].r; b = t[b].r; lo = m; } }
        return res + t[b].c - t[a].c;
    }
};

// ============================================================================
// [D12] 2D prefix sums, compress helpers, difference arrays, histogram
// ============================================================================
template <class T> struct Pref2D {  // sum over [r1,r2) x [c1,c2)
    vector<vector<T>> p;
    Pref2D(const vector<vector<T>> &a) { int n = a.size(), m = n ? a[0].size() : 0; p.assign(n + 1, vector<T>(m + 1, T())); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) p[i + 1][j + 1] = a[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j]; }
    T query(int r1, int c1, int r2, int c2) const { return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1]; }
};
// 1D difference array: d[l]+=v, d[r+1]-=v, then prefix sum.  2D: d[x1][y1]+=v, d[x1][y2+1]-=v, d[x2+1][y1]-=v, d[x2+1][y2+1]+=v
// largest rectangle in histogram (O(n))
ll largestRect(const vector<ll> &h) {
    int n = h.size(); vector<int> st; ll best = 0;
    for (int i = 0; i <= n; i++) { ll cur = (i == n) ? 0 : h[i]; while (!st.empty() && h[st.back()] >= cur) { ll H = h[st.back()]; st.pop_back(); int L = st.empty() ? -1 : st.back(); best = max(best, H * (i - L - 1)); } st.pb(i); }
    return best;
}

// ============================================================================
// [G1] Shortest paths.  Graph = vvi (unweighted) or WG = vector<vector<pll>> {to,w}
// ============================================================================
using WG = vector<vector<pll>>;
vector<int> bfsDist(const vvi &g, int s) { vector<int> d(g.size(), -1); queue<int> q; d[s] = 0; q.push(s); while (!q.empty()) { int u = q.front(); q.pop(); for (int v : g[u]) if (d[v] < 0) { d[v] = d[u] + 1; q.push(v); } } return d; }
vector<ll> dijkstra(const WG &g, int s, vector<int> *par = nullptr) {
    vector<ll> d(g.size(), INF); if (par) par->assign(g.size(), -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq; d[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        pll top = pq.top(); pq.pop(); ll du = top.first; int u = top.second; if (du > d[u]) continue;
        for (const pll &e : g[u]) if (du + e.second < d[e.first]) { d[e.first] = du + e.second; if (par) (*par)[e.first] = u; pq.push({d[e.first], e.first}); }
    }
    return d;
}
vector<ll> bfs01(const WG &g, int s) {  // weights 0/1 only
    vector<ll> d(g.size(), INF); deque<int> q; d[s] = 0; q.push_back(s);
    while (!q.empty()) { int u = q.front(); q.pop_front(); for (const pll &e : g[u]) if (d[u] + e.second < d[e.first]) { d[e.first] = d[u] + e.second; if (e.second) q.push_back(e.first); else q.push_front(e.first); } }
    return d;
}
// Bellman-Ford over edge list {u,v,w}; returns false if a negative cycle is reachable from s
bool bellmanFord(int n, const vector<array<ll, 3>> &E, int s, vector<ll> &d) {
    d.assign(n, INF); d[s] = 0;
    for (int it = 0; it < n; it++) { bool ch = false; for (auto &e : E) if (d[e[0]] < INF && d[e[0]] + e[2] < d[e[1]]) { d[e[1]] = d[e[0]] + e[2]; ch = true; } if (!ch) return true; if (it == n - 1) return false; }
    return true;
}
void floyd(vector<vector<ll>> &d) {  // d[i][j]=INF if no edge, d[i][i]=0
    int n = d.size();
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) { if (d[i][k] >= INF) continue; for (int j = 0; j < n; j++) if (d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j]; }
}
vector<int> getPath(const vector<int> &par, int s, int t) { vector<int> p; for (int v = t; v != -1; v = par[v]) { p.pb(v); if (v == s) break; } reverse(all(p)); return (p.empty() || p[0] != s) ? vector<int>() : p; }
// Dijkstra on state graph: encode state (node, extra) -> id = node*K+extra.  Multi-source: push all sources with d=0.
// bitset transitive closure: vector<bitset<N>> r; for k for i if r[i][k] r[i]|=r[k];
bool isBipartite(const vvi &g, vector<int> &col) {
    int n = g.size(); col.assign(n, -1);
    for (int s = 0; s < n; s++) { if (col[s] >= 0) continue; col[s] = 0; queue<int> q; q.push(s); while (!q.empty()) { int u = q.front(); q.pop(); for (int v : g[u]) { if (col[v] < 0) { col[v] = col[u] ^ 1; q.push(v); } else if (col[v] == col[u]) return false; } } }
    return true;
}

// ============================================================================
// [G2] Topological sort, SCC (iterative Tarjan), 2-SAT
// ============================================================================
vector<int> topoSort(const vvi &g) {  // empty if cycle (n>0)
    int n = g.size(); vector<int> indeg(n, 0), ord; for (int u = 0; u < n; u++) for (int v : g[u]) indeg[v]++;
    queue<int> q; for (int i = 0; i < n; i++) if (!indeg[i]) q.push(i);
    while (!q.empty()) { int u = q.front(); q.pop(); ord.pb(u); for (int v : g[u]) if (--indeg[v] == 0) q.push(v); }
    if ((int)ord.size() != n) ord.clear(); return ord;
}
// returns #components; comp ids are in REVERSE topological order (edges go from higher id to lower id)
int sccTarjan(const vvi &g, vector<int> &comp) {
    int n = g.size(), T = 0, k = 0; vector<int> num(n, -1), low(n, 0), it(n, 0), st; vector<char> on(n, 0); comp.assign(n, -1);
    for (int s = 0; s < n; s++) {
        if (num[s] != -1) continue;
        vector<int> cs = {s}; num[s] = low[s] = T++; st.pb(s); on[s] = 1;
        while (!cs.empty()) {
            int u = cs.back();
            if (it[u] < sz(g[u])) {
                int v = g[u][it[u]++];
                if (num[v] == -1) { num[v] = low[v] = T++; st.pb(v); on[v] = 1; cs.pb(v); }
                else if (on[v]) low[u] = min(low[u], num[v]);
            } else {
                if (low[u] == num[u]) { while (true) { int v = st.back(); st.pop_back(); on[v] = 0; comp[v] = k; if (v == u) break; } k++; }
                cs.pop_back(); if (!cs.empty()) low[cs.back()] = min(low[cs.back()], low[u]);
            }
        }
    }
    return k;
}
// condensation DAG: for u, v in g[u]: if comp[u]!=comp[v] add edge comp[u]->comp[v]
struct TwoSat {  // variables 0..n-1.  literal (x, val): x==val
    int n; vvi g;
    TwoSat(int n) : n(n), g(2 * n) {}
    static int lit(int x, bool val) { return 2 * x + (val ? 0 : 1); }
    void addOr(int a, bool va, int b, bool vb) { g[lit(a, va) ^ 1].pb(lit(b, vb)); g[lit(b, vb) ^ 1].pb(lit(a, va)); }  // (a==va) OR (b==vb)
    void addImply(int a, bool va, int b, bool vb) { addOr(a, !va, b, vb); }
    void addXor(int a, int b) { addOr(a, true, b, true); addOr(a, false, b, false); }   // a != b
    void addEq(int a, int b) { addOr(a, true, b, false); addOr(a, false, b, true); }    // a == b
    void forceVal(int a, bool va) { addOr(a, va, a, va); }
    bool solve(vector<bool> &ans) { vector<int> comp; sccTarjan(g, comp); ans.assign(n, false); for (int i = 0; i < n; i++) { if (comp[2 * i] == comp[2 * i + 1]) return false; ans[i] = comp[2 * i] < comp[2 * i + 1]; } return true; }
};

// ============================================================================
// [G3] Bridges & articulation points (recursive DFS: fine to ~1e5 depth; else iterate/raise stack)
// ============================================================================
struct Bridges {
    int n, T = 0; vector<vector<pii>> g; vector<int> tin, low, isBridge; vector<char> isCut; int m = 0;
    Bridges(int n) : n(n), g(n) {}
    int addEdge(int u, int v) { g[u].pb({v, m}); g[v].pb({u, m}); return m++; }
    void dfs(int u, int pe) {
        tin[u] = low[u] = T++; int ch = 0;
        for (const pii &e : g[u]) {
            if (e.second == pe) continue;
            int v = e.first;
            if (tin[v] != -1) low[u] = min(low[u], tin[v]);
            else { dfs(v, e.second); low[u] = min(low[u], low[v]); if (low[v] > tin[u]) isBridge[e.second] = 1; if (low[v] >= tin[u] && pe != -1) isCut[u] = 1; ch++; }
        }
        if (pe == -1 && ch > 1) isCut[u] = 1;
    }
    void run() { tin.assign(n, -1); low.assign(n, 0); isBridge.assign(m, 0); isCut.assign(n, 0); for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1); }
};
// 2-edge-connected components: DSU-unite endpoints of all non-bridge edges. Block-cut tree: build from articulation points if needed.

// ============================================================================
// [G4] Trees: LCA (binary lifting), Euler tour (tin/tout), diameter, subtree sizes
// ============================================================================
struct LCA {
    int n, LOG; vector<vector<int>> up; vector<int> dep;
    LCA() {}
    LCA(const vvi &g, int root = 0) { build(g, root); }
    void build(const vvi &g, int root = 0) {
        n = g.size(); LOG = 1; while ((1 << LOG) < n) LOG++;
        up.assign(LOG, vector<int>(n, root)); dep.assign(n, 0);
        vector<int> q = {root}; vector<char> seen(n, 0); seen[root] = 1;
        for (int i = 0; i < sz(q); i++) { int u = q[i]; for (int v : g[u]) if (!seen[v]) { seen[v] = 1; up[0][v] = u; dep[v] = dep[u] + 1; q.pb(v); } }
        for (int k = 1; k < LOG; k++) for (int v = 0; v < n; v++) up[k][v] = up[k - 1][up[k - 1][v]];
    }
    int kth(int v, int k) const { if (k > dep[v]) return -1; for (int i = 0; i < LOG; i++) if (k >> i & 1) v = up[i][v]; return v; }
    int lca(int a, int b) const {
        if (dep[a] < dep[b]) swap(a, b);
        a = kth(a, dep[a] - dep[b]); if (a == b) return a;
        for (int i = LOG - 1; i >= 0; i--) if (up[i][a] != up[i][b]) { a = up[i][a]; b = up[i][b]; }
        return up[0][a];
    }
    int dist(int a, int b) const { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
    int jump(int a, int b, int k) const {  // k-th vertex (0-indexed) on path a->b
        int l = lca(a, b), d1 = dep[a] - dep[l]; if (k <= d1) return kth(a, k); return kth(b, dist(a, b) - k);
    }
};
// iterative DFS preorder: tin[u], tout[u] (subtree = [tin, tout)), parent, order. Also subtree sizes.
struct TreeInfo {
    vector<int> par, tin, tout, order, sub, dep;
    TreeInfo(const vvi &g, int root = 0) {
        int n = g.size(); par.assign(n, -1); tin.assign(n, 0); tout.assign(n, 0); sub.assign(n, 1); dep.assign(n, 0);
        vector<int> st = {root}, it(n, 0); int T = 0; tin[root] = T++; order.pb(root);
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < sz(g[u])) { int v = g[u][it[u]++]; if (v == par[u]) continue; par[v] = u; dep[v] = dep[u] + 1; tin[v] = T++; order.pb(v); st.pb(v); }
            else { tout[u] = T; st.pop_back(); if (par[u] >= 0) sub[par[u]] += sub[u]; }
        }
    }
    bool isAnc(int a, int b) const { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
};
// weighted tree distances from s (iterative); diameter returns length, endpoints a,b
vector<ll> treeDist(const WG &g, int s) {
    vector<ll> d(g.size(), -1); vector<int> st = {s}; d[s] = 0;
    while (!st.empty()) { int u = st.back(); st.pop_back(); for (const pll &e : g[u]) if (d[e.first] < 0) { d[e.first] = d[u] + e.second; st.pb(e.first); } }
    return d;
}
ll treeDiameter(const WG &g, int &a, int &b) {
    auto d0 = treeDist(g, 0); a = max_element(all(d0)) - d0.begin();
    auto d1 = treeDist(g, a); b = max_element(all(d1)) - d1.begin(); return d1[b];
}
// Subtree DP pattern: iterate TreeInfo::order in reverse and merge child into par[u].
// Rerooting: down[u] from reverse order, then up[v] from order using prefix/suffix of siblings' contributions.

// ============================================================================
// [G5] Heavy-Light Decomposition (iterative). pos[] preorder with heavy child first.
//   Subtree of u = [pos[u], pos[u]+sz[u]).  Path ops via callbacks f(l,r) on [l,r) ranges.
//   Vertex-weights: pathQuery(a,b,f).  Edge-weights stored at child: pathQuery(a,b,f,true).
// ============================================================================
struct HLD {
    int n; vvi g; vector<int> par, dep, heavy, head, pos, sz_, order;
    HLD(int n) : n(n), g(n) {}
    void addEdge(int u, int v) { g[u].pb(v); g[v].pb(u); }
    void build(int root = 0) {
        par.assign(n, -1); dep.assign(n, 0); heavy.assign(n, -1); head.assign(n, 0); pos.assign(n, 0); sz_.assign(n, 1); order.clear();
        order.pb(root);
        for (int i = 0; i < sz(order); i++) { int u = order[i]; for (int v : g[u]) if (v != par[u]) { par[v] = u; dep[v] = dep[u] + 1; order.pb(v); } }
        for (int i = n - 1; i > 0; i--) { int u = order[i]; sz_[par[u]] += sz_[u]; }
        for (int u : order) { int best = 0; for (int v : g[u]) if (v != par[u] && sz_[v] > best) { best = sz_[v]; heavy[u] = v; } }
        vector<int> st = {root}; head[root] = root; int cur = 0;
        while (!st.empty()) {
            int u = st.back(); st.pop_back(); pos[u] = cur++;
            for (int v : g[u]) if (v != par[u] && v != heavy[u]) { head[v] = v; st.pb(v); }
            if (heavy[u] != -1) { head[heavy[u]] = head[u]; st.pb(heavy[u]); }
        }
    }
    int lca(int a, int b) const { while (head[a] != head[b]) { if (dep[head[a]] > dep[head[b]]) a = par[head[a]]; else b = par[head[b]]; } return dep[a] < dep[b] ? a : b; }
    template <class F> void pathQuery(int a, int b, F f, bool edges = false) {  // f(l,r) half-open, commutative combine
        while (head[a] != head[b]) { if (dep[head[a]] < dep[head[b]]) swap(a, b); f(pos[head[a]], pos[a] + 1); a = par[head[a]]; }
        if (dep[a] > dep[b]) swap(a, b);
        if (pos[a] + edges < pos[b] + 1) f(pos[a] + edges, pos[b] + 1);
    }
    pii subtree(int u) const { return {pos[u], pos[u] + sz_[u]}; }
};

// ============================================================================
// [G6] Centroid decomposition: cpar[v] = parent in centroid tree (-1 for root)
//   Pattern: for query/update at v: for(c=v;c!=-1;c=cpar[c]) use dist(v,c) (via LCA struct)
// ============================================================================
struct Centroid {
    int n; const vvi &g; vector<int> cpar, sz_, pr; vector<char> rem;
    Centroid(const vvi &g) : n(g.size()), g(g) { build(); }
    int centroid(int s) {
        vector<int> q = {s}; pr[s] = -1;
        for (int i = 0; i < sz(q); i++) { int u = q[i]; sz_[u] = 1; for (int v : g[u]) if (!rem[v] && v != pr[u]) { pr[v] = u; q.pb(v); } }
        for (int i = sz(q) - 1; i > 0; i--) sz_[pr[q[i]]] += sz_[q[i]];
        int tot = sz(q);
        for (int u : q) { int mx = tot - sz_[u]; for (int v : g[u]) if (!rem[v] && v != pr[u]) mx = max(mx, sz_[v]); if (mx * 2 <= tot) return u; }
        return s;
    }
    void build() {
        cpar.assign(n, -1); sz_.assign(n, 0); pr.assign(n, -1); rem.assign(n, 0);
        vector<pii> st = {{0, -1}};
        while (!st.empty()) { pii x = st.back(); st.pop_back(); int c = centroid(x.first); cpar[c] = x.second; rem[c] = 1; for (int v : g[c]) if (!rem[v]) st.pb({v, c}); }
    }
};

// ============================================================================
// [G7] MST (Kruskal).  edges: {w,u,v}.  Returns total weight (or -1 if disconnected); used[i]=1 if edge in MST
// ============================================================================
ll kruskal(int n, vector<array<ll, 3>> E, vector<int> *used = nullptr) {
    vector<int> idx(E.size()); iota(all(idx), 0); sort(all(idx), [&](int a, int b) { return E[a][0] < E[b][0]; });
    DSU d(n); ll tot = 0; int cnt = 0; if (used) used->assign(E.size(), 0);
    for (int i : idx) if (d.unite((int)E[i][1], (int)E[i][2])) { tot += E[i][0]; cnt++; if (used) (*used)[i] = 1; }
    return cnt == n - 1 ? tot : -1;
}
// Prim: Dijkstra-like with pq of (w,v) and `inMST` array.  Second-best MST: for each non-MST edge, max edge on MST path (binary lifting).
// Boruvka / Directed MST (Chu-Liu) are rare; Min bottleneck path = path in MST.

// ============================================================================
// [G8] Max flow (Dinic) & min-cost max-flow (SPFA)
//   Dinic D(n); id=D.addEdge(u,v,cap); D.maxflow(s,t); flow on edge id = D.e[id^1].cap
//   Undirected edge: addEdge(u,v,c,c).  Bipartite matching / project selection / min cut as flow.
// ============================================================================
struct Dinic {
    struct E { int to; ll cap; };
    int n; vector<E> e; vector<vector<int>> g; vector<int> level, it;
    Dinic(int n) : n(n), g(n) {}
    int addEdge(int u, int v, ll cap, ll rcap = 0) { int id = e.size(); g[u].pb(id); e.pb({v, cap}); g[v].pb(id + 1); e.pb({u, rcap}); return id; }
    bool bfs(int s, int t) {
        level.assign(n, -1); level[s] = 0; queue<int> q; q.push(s);
        while (!q.empty()) { int u = q.front(); q.pop(); for (int id : g[u]) if (e[id].cap > 0 && level[e[id].to] < 0) { level[e[id].to] = level[u] + 1; q.push(e[id].to); } }
        return level[t] >= 0;
    }
    ll dfs(int u, int t, ll f) {
        if (u == t) return f;
        for (int &i = it[u]; i < sz(g[u]); i++) {
            int id = g[u][i], v = e[id].to;
            if (e[id].cap > 0 && level[v] == level[u] + 1) { ll r = dfs(v, t, min(f, e[id].cap)); if (r > 0) { e[id].cap -= r; e[id ^ 1].cap += r; return r; } }
        }
        return 0;
    }
    ll maxflow(int s, int t) { ll fl = 0; while (bfs(s, t)) { it.assign(n, 0); while (ll f = dfs(s, t, INF)) fl += f; } return fl; }
    vector<bool> minCutSide(int s) { vector<bool> vis(n, false); queue<int> q; q.push(s); vis[s] = true; while (!q.empty()) { int u = q.front(); q.pop(); for (int id : g[u]) if (e[id].cap > 0 && !vis[e[id].to]) { vis[e[id].to] = true; q.push(e[id].to); } } return vis; }  // true = source side
};
struct MCMF {
    struct E { int to; ll cap, cost; };
    int n; vector<E> e; vector<vector<int>> g;
    MCMF(int n) : n(n), g(n) {}
    int addEdge(int u, int v, ll cap, ll cost) { int id = e.size(); g[u].pb(id); e.pb({v, cap, cost}); g[v].pb(id + 1); e.pb({u, 0, -cost}); return id; }
    pair<ll, ll> flow(int s, int t, ll maxf = INF) {  // {flow, cost}
        ll fl = 0, cost = 0;
        while (fl < maxf) {
            vector<ll> d(n, INF); vector<int> pe(n, -1); vector<char> inq(n, 0); deque<int> q; d[s] = 0; q.push_back(s);
            while (!q.empty()) { int u = q.front(); q.pop_front(); inq[u] = 0; for (int id : g[u]) if (e[id].cap > 0 && d[u] + e[id].cost < d[e[id].to]) { d[e[id].to] = d[u] + e[id].cost; pe[e[id].to] = id; if (!inq[e[id].to]) { inq[e[id].to] = 1; q.push_back(e[id].to); } } }
            if (d[t] >= INF) break;
            ll f = maxf - fl; for (int v = t; v != s; v = e[pe[v] ^ 1].to) f = min(f, e[pe[v]].cap);
            for (int v = t; v != s; v = e[pe[v] ^ 1].to) { e[pe[v]].cap -= f; e[pe[v] ^ 1].cap += f; }
            fl += f; cost += f * d[t];
        }
        return {fl, cost};
    }
};

// ============================================================================
// [G9] Bipartite matching (Hopcroft-Karp), assignment problem (Hungarian)
//   HK h(nL,nR); h.add(u,v); h.run() -> size; matchL[u]=v or -1.  Konig: min vertex cover = max matching,
//   max independent set = n - matching, min path cover (DAG) = n - matching.
// ============================================================================
struct HK {
    int n, m; vvi g; vector<int> mL, mR, dist, it;
    HK(int n, int m) : n(n), m(m), g(n), mL(n, -1), mR(m, -1) {}
    void add(int u, int v) { g[u].pb(v); }
    bool bfs() {
        queue<int> q; dist.assign(n, -1);
        for (int u = 0; u < n; u++) if (mL[u] < 0) { dist[u] = 0; q.push(u); }
        bool found = false;
        while (!q.empty()) { int u = q.front(); q.pop(); for (int v : g[u]) { int w = mR[v]; if (w < 0) found = true; else if (dist[w] < 0) { dist[w] = dist[u] + 1; q.push(w); } } }
        return found;
    }
    bool dfs(int u) {
        for (int &i = it[u]; i < sz(g[u]); i++) { int v = g[u][i], w = mR[v]; if (w < 0 || (dist[w] == dist[u] + 1 && dfs(w))) { mL[u] = v; mR[v] = u; return true; } }
        dist[u] = -1; return false;
    }
    int run() { int r = 0; while (bfs()) { it.assign(n, 0); for (int u = 0; u < n; u++) if (mL[u] < 0 && dfs(u)) r++; } return r; }
};
// Min-cost perfect assignment, a is 1-indexed [1..n][1..m], n<=m. ans[row]=col. Returns min total cost.
ll hungarian(const vector<vector<ll>> &a, vector<int> &ans) {
    int n = a.size() - 1, m = a[0].size() - 1; const ll BIG = 1e18;
    vector<ll> u(n + 1, 0), v(m + 1, 0); vector<int> p(m + 1, 0), way(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[0] = i; int j0 = 0; vector<ll> minv(m + 1, BIG); vector<char> used(m + 1, 0);
        do {
            used[j0] = 1; int i0 = p[j0], j1 = 0; ll delta = BIG;
            for (int j = 1; j <= m; j++) if (!used[j]) { ll cur = a[i0][j] - u[i0] - v[j]; if (cur < minv[j]) { minv[j] = cur; way[j] = j0; } if (minv[j] < delta) { delta = minv[j]; j1 = j; } }
            for (int j = 0; j <= m; j++) if (used[j]) { u[p[j]] += delta; v[j] -= delta; } else minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do { int j1 = way[j0]; p[j0] = p[j1]; j0 = j1; } while (j0);
    }
    ans.assign(n + 1, 0); for (int j = 1; j <= m; j++) if (p[j]) ans[p[j]] = j;
    return -v[0];
}

// ============================================================================
// [G10] Euler path / circuit (Hierholzer, iterative). Returns vertex sequence or empty if impossible
// ============================================================================
vector<int> eulerPath(int n, const vector<pii> &edges, bool directed) {
    int m = edges.size(); if (!m) return {};
    vector<vector<pii>> g(n); vector<int> in(n, 0), out(n, 0);
    for (int i = 0; i < m; i++) { int u = edges[i].first, v = edges[i].second; g[u].pb({v, i}); out[u]++; in[v]++; if (!directed) g[v].pb({u, i}); }
    int start = -1;
    if (directed) {
        int s = 0, t = 0;
        for (int v = 0; v < n; v++) { if (out[v] - in[v] == 1) { s++; start = v; } else if (in[v] - out[v] == 1) t++; else if (in[v] != out[v]) return {}; }
        if (!((s == 0 && t == 0) || (s == 1 && t == 1))) return {};
        if (start < 0) for (int v = 0; v < n; v++) if (out[v]) { start = v; break; }
    } else {
        int odd = 0; for (int v = 0; v < n; v++) if ((in[v] + out[v]) & 1) { odd++; if (start < 0) start = v; }
        if (odd != 0 && odd != 2) return {};
        if (start < 0) for (int v = 0; v < n; v++) if (!g[v].empty()) { start = v; break; }
    }
    vector<char> used(m, 0); vector<int> ptr(n, 0), st = {start}, res;
    while (!st.empty()) {
        int u = st.back(); while (ptr[u] < sz(g[u]) && used[g[u][ptr[u]].second]) ptr[u]++;
        if (ptr[u] == sz(g[u])) { res.pb(u); st.pop_back(); }
        else { pii e = g[u][ptr[u]++]; used[e.second] = 1; st.pb(e.first); }
    }
    if (sz(res) != m + 1) return {};
    reverse(all(res)); return res;
}

// ============================================================================
// [S1] Z-function, prefix function (KMP), pattern search, periods
// ============================================================================
vector<int> zFunc(const string &s) {  // z[i]=LCP(s, s[i..]), z[0]=n
    int n = s.size(); vector<int> z(n, 0); z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) { if (i < r) z[i] = min(r - i, z[i - l]); while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++; if (i + z[i] > r) { l = i; r = i + z[i]; } }
    return z;
}
vector<int> prefixFunc(const string &s) {  // pi[i]=longest proper border of s[0..i]
    int n = s.size(); vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) { int k = pi[i - 1]; while (k > 0 && s[i] != s[k]) k = pi[k - 1]; if (s[i] == s[k]) k++; pi[i] = k; }
    return pi;
}
vector<int> kmpFind(const string &text, const string &pat) {  // all start positions of pat in text
    string t = pat + '\1' + text; auto pi = prefixFunc(t); vector<int> r; int m = pat.size();
    for (int i = m + 1; i < sz(t); i++) if (pi[i] == m) r.pb(i - 2 * m);
    return r;
}
// smallest period of s = n - pi[n-1] (full repeats if n % period == 0).  All borders: follow pi chain.
// Count occurrences of each prefix: cnt[pi[i]]++ then propagate for i=n-1..1: cnt[pi[i-1]]+=cnt[i]

// ============================================================================
// [S2] Polynomial rolling hash mod 2^61-1 (random base).  Hash61 H(s); H.get(l,r) for [l,r)
// ============================================================================
struct Hash61 {
    static const ull M = (1ULL << 61) - 1;
    ull base; vector<ull> h, pw;
    static ull mul(ull a, ull b) {
#ifdef __SIZEOF_INT128__
        u128 t = (u128)a * b; ull r = (ull)(t >> 61) + (ull)(t & M); if (r >= M) r -= M; return r;
#else
        return mulmod(a, b, M);
#endif
    }
    Hash61(const string &s) : base(rng() % (M - 1000) + 500) {
        int n = s.size(); h.assign(n + 1, 0); pw.assign(n + 1, 1);
        for (int i = 0; i < n; i++) { h[i + 1] = mul(h[i], base) + (unsigned char)s[i] + 1; if (h[i + 1] >= M) h[i + 1] -= M; pw[i + 1] = mul(pw[i], base); }
    }
    ull get(int l, int r) const { return (h[r] + M - mul(h[l], pw[r - l])) % M; }
};
// Palindrome check via hash: compare get on s and on reversed s. Double mod alternative: pair of (mod1,mod2).

// ============================================================================
// [S3] Manacher.  d1[i]=#odd palindromes centred i (radius incl. centre); d2[i]=#even centred between i-1,i
// ============================================================================
pair<vector<int>, vector<int>> manacher(const string &s) {
    int n = s.size(); vector<int> d1(n), d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) { int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1); while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++; d1[i] = k--; if (i + k > r) { l = i - k; r = i + k; } }
    for (int i = 0, l = 0, r = -1; i < n; i++) { int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1); while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++; d2[i] = k--; if (i + k > r) { l = i - k - 1; r = i + k; } }
    return {d1, d2};
}
string longestPalSub(const string &s) {
    auto pr = manacher(s); int best = 0, st = 0, n = s.size();
    for (int i = 0; i < n; i++) { if (2 * pr.first[i] - 1 > best) { best = 2 * pr.first[i] - 1; st = i - pr.first[i] + 1; } if (2 * pr.second[i] > best) { best = 2 * pr.second[i]; st = i - pr.second[i]; } }
    return s.substr(st, best);
}

// ============================================================================
// [S4] Suffix array O(n log n) + LCP (Kasai).  Distinct substrings = n(n+1)/2 - sum(lcp)
//   lcp[i] = LCP(sa[i], sa[i+1]).  LCP of arbitrary suffixes = range-min on lcp (Sparse table).
// ============================================================================
vector<int> suffixArray(string s) {
    s += char(1); int n = s.size(); const int A = 256;
    vector<int> p(n), c(n), cnt(max(A, n), 0);
    for (int i = 0; i < n; i++) cnt[(unsigned char)s[i]]++;
    for (int i = 1; i < A; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[(unsigned char)s[i]]] = i;
    c[p[0]] = 0; int cl = 1;
    for (int i = 1; i < n; i++) { if (s[p[i]] != s[p[i - 1]]) cl++; c[p[i]] = cl - 1; }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) { pn[i] = p[i] - (1 << h); if (pn[i] < 0) pn[i] += n; }
        fill(cnt.begin(), cnt.begin() + cl, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < cl; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0; cl = 1;
        for (int i = 1; i < n; i++) { pii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]}, prv = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]}; if (cur != prv) cl++; cn[p[i]] = cl - 1; }
        c.swap(cn);
    }
    p.erase(p.begin()); return p;
}
vector<int> lcpKasai(const string &s, const vector<int> &sa) {
    int n = s.size(), k = 0; vector<int> rk(n), lcp(n, 0);
    for (int i = 0; i < n; i++) rk[sa[i]] = i;
    for (int i = 0; i < n; i++) { if (rk[i] == n - 1) { k = 0; continue; } int j = sa[rk[i] + 1]; while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++; lcp[rk[i]] = k; if (k) k--; }
    return lcp;
}

// ============================================================================
// [S5] Aho-Corasick (26 lowercase).  add patterns, build(), then walk text via go[][]
//   cnt[v] = number of patterns that are suffixes of state v's string (after build)
// ============================================================================
struct AhoCorasick {
    vector<array<int, 26>> go; vector<int> link, cnt;
    AhoCorasick() { newNode(); }
    int newNode() { array<int, 26> a; a.fill(-1); go.pb(a); link.pb(0); cnt.pb(0); return go.size() - 1; }
    int add(const string &s) { int u = 0; for (char ch : s) { int c = ch - 'a'; if (go[u][c] < 0) { int v = newNode(); go[u][c] = v; } u = go[u][c]; } cnt[u]++; return u; }
    void build() {
        queue<int> q;
        for (int c = 0; c < 26; c++) { int v = go[0][c]; if (v < 0) go[0][c] = 0; else { link[v] = 0; q.push(v); } }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int c = 0; c < 26; c++) { int v = go[u][c]; if (v < 0) go[u][c] = go[link[u]][c]; else { link[v] = go[link[u]][c]; cnt[v] += cnt[link[v]]; q.push(v); } }
        }
    }
    ll countMatches(const string &t) const { ll r = 0; int u = 0; for (char ch : t) { u = go[u][ch - 'a']; r += cnt[u]; } return r; }  // total (pattern, end position) pairs
};

// ============================================================================
// [S6] Suffix automaton (26 lowercase): distinct substrings, occurrence counts, LCS of two strings
// ============================================================================
struct SAM {
    struct St { int len, link; ll cnt; array<int, 26> nx; };
    vector<St> st; int last;
    static St mk(int len, int link, ll cnt) { St s; s.len = len; s.link = link; s.cnt = cnt; s.nx.fill(-1); return s; }
    SAM() { st.pb(mk(0, -1, 0)); last = 0; }
    void extend(char ch) {
        int c = ch - 'a', cur = st.size(); st.pb(mk(st[last].len + 1, 0, 1)); int p = last;
        while (p != -1 && st[p].nx[c] == -1) { st[p].nx[c] = cur; p = st[p].link; }
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].nx[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int cl = st.size(); St cp = st[q]; cp.len = st[p].len + 1; cp.cnt = 0; st.pb(cp);
                while (p != -1 && st[p].nx[c] == q) { st[p].nx[c] = cl; p = st[p].link; }
                st[q].link = st[cur].link = cl;
            }
        }
        last = cur;
    }
    void build(const string &s) { for (char ch : s) extend(ch); }
    ll distinctSubstrings() const { ll r = 0; for (int i = 1; i < sz(st); i++) r += st[i].len - st[st[i].link].len; return r; }
    void calcOccurrences() {  // st[v].cnt = #occurrences of strings in state v
        vector<int> ord(st.size()); iota(all(ord), 0); sort(all(ord), [&](int a, int b) { return st[a].len > st[b].len; });
        for (int v : ord) if (st[v].link >= 0) st[st[v].link].cnt += st[v].cnt;
    }
    int longestCommonSubstring(const string &t) const {  // longest substring of t that occurs in the built string
        int v = 0, l = 0, best = 0;
        for (char ch : t) { int c = ch - 'a'; while (v && st[v].nx[c] == -1) { v = st[v].link; l = st[v].len; } if (st[v].nx[c] != -1) { v = st[v].nx[c]; l++; } best = max(best, l); }
        return best;
    }
};

// ============================================================================
// [S7] Minimal rotation, Lyndon factorization (Duval)
// ============================================================================
int minRotation(const string &s) {  // start index of lexicographically smallest rotation
    int n = s.size(), i = 0, j = 1, k = 0; string t = s + s;
    while (i < n && j < n && k < n) { char a = t[i + k], b = t[j + k]; if (a == b) { k++; continue; } if (a > b) i += k + 1; else j += k + 1; if (i == j) j++; k = 0; }
    return min(i, j);
}

// ============================================================================
// [P1] LIS / LCS / edit distance / Kadane / inversions
// ============================================================================
int lisLen(const vector<ll> &a, bool strict = true) {  // O(n log n)
    vector<ll> t; for (ll x : a) { auto it = strict ? lower_bound(all(t), x) : upper_bound(all(t), x); if (it == t.end()) t.pb(x); else *it = x; } return t.size();
}
vector<ll> lisSeq(const vector<ll> &a) {  // strict LIS reconstruction
    int n = a.size(); vector<ll> t; vector<int> idx, par(n, -1);
    for (int i = 0; i < n; i++) { int p = lower_bound(all(t), a[i]) - t.begin(); if (p == sz(t)) { t.pb(a[i]); idx.pb(i); } else { t[p] = a[i]; idx[p] = i; } par[i] = p ? idx[p - 1] : -1; }
    vector<ll> r; for (int i = idx.empty() ? -1 : idx.back(); i != -1; i = par[i]) r.pb(a[i]); reverse(all(r)); return r;
}
string lcsStr(const string &a, const string &b) {
    int n = a.size(), m = b.size(); vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    string r; for (int i = n, j = m; i > 0 && j > 0;) { if (a[i - 1] == b[j - 1]) { r += a[i - 1]; i--; j--; } else if (dp[i - 1][j] >= dp[i][j - 1]) i--; else j--; }
    reverse(all(r)); return r;
}
int editDistance(const string &a, const string &b) {
    int n = a.size(), m = b.size(); vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i; for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
    return dp[n][m];
}
// longest palindromic subsequence = LCS(s, reverse(s)).  Distinct subsequences: dp[i]=2*dp[i-1]-dp[last[c]-1]
// max subarray sum (Kadane) with indices [l,r]; allow empty -> max(0, best)
ll kadane(const vector<ll> &a, int &L, int &R) {
    ll best = a[0], cur = a[0]; int s = 0; L = R = 0;
    for (int i = 1; i < sz(a); i++) { if (cur < 0) { cur = a[i]; s = i; } else cur += a[i]; if (cur > best) { best = cur; L = s; R = i; } }
    return best;
}
ll inversions(vector<ll> a) {  // merge sort count of pairs i<j, a[i]>a[j]
    int n = a.size(); vector<ll> tmp(n); ll cnt = 0;
    function<void(int, int)> rec = [&](int l, int r) {
        if (r - l < 2) return; int m = (l + r) / 2; rec(l, m); rec(m, r); int i = l, j = m, k = l;
        while (i < m && j < r) { if (a[i] <= a[j]) tmp[k++] = a[i++]; else { tmp[k++] = a[j++]; cnt += m - i; } }
        while (i < m) tmp[k++] = a[i++]; while (j < r) tmp[k++] = a[j++];
        for (int x = l; x < r; x++) a[x] = tmp[x];
    };
    rec(0, n); return cnt;
}
// #subarrays with sum==k: prefix sums + hash map; with sum<=k and positives: two pointers.

// ============================================================================
// [P2] Knapsack family
// ============================================================================
ll knapsack01(const vector<int> &w, const vector<ll> &v, int W) { vector<ll> dp(W + 1, 0); for (int i = 0; i < sz(w); i++) for (int c = W; c >= w[i]; c--) dp[c] = max(dp[c], dp[c - w[i]] + v[i]); return dp[W]; }
ll knapsackUnbounded(const vector<int> &w, const vector<ll> &v, int W) { vector<ll> dp(W + 1, 0); for (int i = 0; i < sz(w); i++) for (int c = w[i]; c <= W; c++) dp[c] = max(dp[c], dp[c - w[i]] + v[i]); return dp[W]; }
// bounded knapsack: split count k into 1,2,4,...,rest items then 0/1.  Subset sum: bitset<N> b; b[0]=1; for x: b|=b<<x;
// coin change (#ways): dp[0]=1; for coin: for c=coin..S: dp[c]+=dp[c-coin].  (min coins): dp[c]=min(dp[c],dp[c-coin]+1)
// when W huge but values small: dp over value -> min weight. Meet-in-the-middle for n<=40.

// ============================================================================
// [P3] Bitmask DP: SOS (subset/superset sums), TSP, submask enumeration
// ============================================================================
void sosSubset(vector<ll> &f, int B) { for (int i = 0; i < B; i++) for (int m = 0; m < (1 << B); m++) if (m >> i & 1) f[m] += f[m ^ (1 << i)]; }       // f[m]=sum over submasks
void sosSuperset(vector<ll> &f, int B) { for (int i = 0; i < B; i++) for (int m = 0; m < (1 << B); m++) if (!(m >> i & 1)) f[m] += f[m ^ (1 << i)]; }  // sum over supermasks
// for(int s=m; s; s=(s-1)&m) {...}  /* all non-empty submasks of m (add s=0 separately) */   total 3^n over all masks
// for(int s=0; s<(1<<n); s++) popcount via __builtin_popcount;  next combination with k bits (Gosper):
// int c=x&-x, r=x+c; x=(((r^x)>>2)/c)|r;
ll tsp(const vector<vector<ll>> &d) {  // min Hamiltonian cycle from 0, n<=20
    int n = d.size(); vector<vector<ll>> dp(1 << n, vector<ll>(n, INF)); dp[1][0] = 0;
    for (int m = 1; m < (1 << n); m++) for (int l = 0; l < n; l++) { if (dp[m][l] >= INF || !(m >> l & 1)) continue; for (int x = 0; x < n; x++) if (!(m >> x & 1)) dp[m | 1 << x][x] = min(dp[m | 1 << x][x], dp[m][l] + d[l][x]); }
    ll best = INF; for (int l = 0; l < n; l++) if (dp[(1 << n) - 1][l] < INF) best = min(best, dp[(1 << n) - 1][l] + d[l][0]); return best;
}

// ============================================================================
// [P4] Digit DP: count x in [0,N] with digit sum == S.   Range [L,R] = f(R) - f(L-1)
//   Extend state with: started (leading zeros), last digit, remainder mod K, etc.
// ============================================================================
ll digitSumCount(const string &N, int S) {
    int L = N.size(); vector<vector<ll>> memo(L + 1, vector<ll>(S + 1, -1));
    function<ll(int, int, bool)> go = [&](int pos, int sum, bool tight) -> ll {
        if (sum > S) return 0; if (pos == L) return sum == S;
        if (!tight && memo[pos][sum] != -1) return memo[pos][sum];
        int lim = tight ? N[pos] - '0' : 9; ll r = 0;
        for (int d = 0; d <= lim; d++) r += go(pos + 1, sum + d, tight && d == lim);
        if (!tight) memo[pos][sum] = r; return r;
    };
    return go(0, 0, true);
}

// ============================================================================
// [P5] Divide & conquer DP optimisation:  cur[j] = min_{k<j} prev[k] + cost(k,j)  (opt monotone)
//   call dcOpt(0, n-1, 0, n-1, cur, prev, cost)   cur must be pre-filled with INF
//   Other optimisations: Knuth (interval dp, opt[i][j-1]<=opt[i][j]<=opt[i+1][j]), CHT/Li Chao [D9], bitset speed-ups.
// ============================================================================
template <class C> void dcOpt(int l, int r, int optl, int optr, vector<ll> &cur, const vector<ll> &prev, C cost) {
    if (l > r) return; int m = (l + r) / 2; ll best = INF; int bk = optl;
    for (int k = optl; k <= min(m - 1, optr); k++) { if (prev[k] >= INF) continue; ll v = prev[k] + cost(k, m); if (v < best) { best = v; bk = k; } }
    cur[m] = best; dcOpt(l, m - 1, optl, bk, cur, prev, cost); dcOpt(m + 1, r, bk, optr, cur, prev, cost);
}

// ============================================================================
// [Y1] Geometry: points, hull, area, segments, polygon tests, circles
// ============================================================================
template <class T> struct Pt {
    T x, y; Pt(T x = 0, T y = 0) : x(x), y(y) {}
    Pt operator+(const Pt &o) const { return Pt(x + o.x, y + o.y); }
    Pt operator-(const Pt &o) const { return Pt(x - o.x, y - o.y); }
    Pt operator*(T k) const { return Pt(x * k, y * k); }
    T dot(const Pt &o) const { return x * o.x + y * o.y; }
    T cross(const Pt &o) const { return x * o.y - y * o.x; }
    T n2() const { return x * x + y * y; }
    bool operator<(const Pt &o) const { return x != o.x ? x < o.x : y < o.y; }
    bool operator==(const Pt &o) const { return x == o.x && y == o.y; }
};
using P = Pt<ll>; using PD = Pt<double>;
int sgn(ll v) { return (v > 0) - (v < 0); }
vector<P> convexHull(vector<P> p) {  // CCW, no collinear points
    sort(all(p)); p.erase(unique(all(p)), p.end()); int n = p.size(); if (n <= 2) return p;
    vector<P> h(2 * n); int k = 0;
    for (int i = 0; i < n; i++) { while (k >= 2 && (h[k - 1] - h[k - 2]).cross(p[i] - h[k - 2]) <= 0) k--; h[k++] = p[i]; }
    for (int i = n - 2, t = k + 1; i >= 0; i--) { while (k >= t && (h[k - 1] - h[k - 2]).cross(p[i] - h[k - 2]) <= 0) k--; h[k++] = p[i]; }
    h.resize(k - 1); return h;
}
ll area2(const vector<P> &p) { ll s = 0; int n = p.size(); for (int i = 0; i < n; i++) s += p[i].cross(p[(i + 1) % n]); return s; }  // twice the signed area (CCW>0)
bool onSeg(P a, P b, P q) { return (b - a).cross(q - a) == 0 && (a - q).dot(b - q) <= 0; }
int inPolygon(const vector<P> &p, P q) {  // 0 outside, 1 inside, 2 boundary (any simple polygon)
    bool in = false; int n = p.size();
    for (int i = 0; i < n; i++) {
        P a = p[i], b = p[(i + 1) % n]; if (onSeg(a, b, q)) return 2;
        if ((a.y > q.y) != (b.y > q.y)) { ll c = (b - a).cross(q - a); if ((c > 0) == (b.y > a.y)) in = !in; }
    }
    return in;
}
bool segInter(P a, P b, P c, P d) {  // closed segments intersect (touching counts)
    int d1 = sgn((b - a).cross(c - a)), d2 = sgn((b - a).cross(d - a)), d3 = sgn((d - c).cross(a - c)), d4 = sgn((d - c).cross(b - c));
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    return onSeg(a, b, c) || onSeg(a, b, d) || onSeg(c, d, a) || onSeg(c, d, b);
}
bool lineInter(PD a, PD b, PD c, PD d, PD &out) {  // infinite lines ab and cd
    double den = (b - a).cross(d - c); if (fabs(den) < 1e-12) return false;
    out = a + (b - a) * ((c - a).cross(d - c) / den); return true;
}
double distPointSeg(PD a, PD b, PD q) { PD ab = b - a; double t = ab.n2() < 1e-18 ? 0 : max(0.0, min(1.0, (q - a).dot(ab) / ab.n2())); PD pr = a + ab * t; return sqrt((q - pr).n2()); }
ll diameter2(const vector<P> &h) {  // farthest pair squared (hull CCW), rotating calipers
    int n = h.size(); if (n == 1) return 0; if (n == 2) return (h[0] - h[1]).n2(); ll best = 0;
    for (int i = 0, j = 1; i < n; i++) { while ((h[(i + 1) % n] - h[i]).cross(h[(j + 1) % n] - h[j]) > 0) j = (j + 1) % n; best = max(best, max((h[i] - h[j]).n2(), (h[(i + 1) % n] - h[j]).n2())); }
    return best;
}
// angle sort around origin: half(p) = (y<0 || (y==0 && x<0)); sort by half, then cross>0.  Pick: A = I + B/2 - 1.  Euler: V-E+F=2
// Circle-circle / circle-line intersections: solve via d, a=(r1^2-r2^2+d^2)/(2d), h=sqrt(r1^2-a^2).

// ============================================================================
// [Y2] Closest pair of points (squared distance), O(n log n) sweep
// ============================================================================
ll closestPair2(vector<P> p) {
    sort(all(p)); set<pll> s; ll best = 4e18; int j = 0;
    for (int i = 0; i < sz(p); i++) {
        while (j < i && (p[i].x - p[j].x) * (p[i].x - p[j].x) >= best) { s.erase({p[j].y, p[j].x}); j++; }
        ll d = (ll)sqrtl((ld)best) + 1; if (best == (ll)4e18) d = 4e9;
        for (auto it = s.lower_bound({p[i].y - d, -INF}); it != s.end() && it->first <= p[i].y + d; ++it) best = min(best, (P(it->second, it->first) - p[i]).n2());
        s.insert({p[i].y, p[i].x});
    }
    return best;
}

// ============================================================================
// [A1] Interactive / game-bot I/O.   !!! cin.tie(nullptr) in main => MUST flush after every output !!!
//   ask(q): print query, flush, read reply.  Exit immediately on reply -1 (judge says wrong/limit).
//   Never mix printf/scanf with cin/cout once sync_with_stdio(false).  `endl` here is '\n' (no flush).
// ============================================================================
template <class T> T ask(const string &q) { cout << q << '\n' << flush; T r; cin >> r; if (r == T(-1)) exit(0); return r; }
// Game/bot loop skeleton:  while (cin >> tok) { if (tok=="END") break; ...read state...; cout << move << '\n' << flush; }
// Read-until-EOF: string line; while (getline(cin, line)) {...}.  After `cin >> n` before getline: cin.ignore(numeric_limits<streamsize>::max(), '\n');
// Time-box AI search: Timer T; while (T.ms() < 900) {...}.  Use fixed seed (mt19937) for reproducible debugging.

// ============================================================================
// [A2] Game theory: mex, Grundy, nim, negamax + alpha-beta
// ============================================================================
int mex(vector<int> v) { sort(all(v)); v.erase(unique(all(v)), v.end()); int m = 0; for (int x : v) { if (x == m) m++; else if (x > m) break; } return m; }
// Grundy: g[state] = mex{ g[next] }.  Sum of independent games: XOR of grundys; first player wins iff XOR != 0.
// Nim: XOR of piles. Misere nim: if all piles <=1 first wins iff XOR==0, else same as normal.
// Staircase nim: XOR of piles at odd steps. Subtract-set game: g[n]=mex{g[n-s]}.  Wythoff pairs: (floor(k*phi), floor(k*phi^2)).
// Normal-play win/lose memo: win[s] = exists move to losing state. Bitmask games: dp over masks (<= 2^20).
// Generic negamax with alpha-beta. S must define: terminal(), eval() (from side-to-move view), moves() -> vector<M>, apply(M), undo(M)
template <class S> int negamax(S &s, int depth, int alpha, int beta) {
    if (depth == 0 || s.terminal()) return s.eval();
    int best = -INF32;
    for (auto m : s.moves()) { s.apply(m); int v = -negamax(s, depth - 1, -beta, -alpha); s.undo(m); best = max(best, v); alpha = max(alpha, v); if (alpha >= beta) break; }
    return best;
}
// Iterative deepening: for d=1..D while Timer under limit; keep best move of last complete depth. Add transposition table (Zobrist hash via rng()).

// ============================================================================
// [A3] Reading patterns / output formatting notes
// ============================================================================
//  - cout << fixed << setprecision(k) already set in main. For long double use ld and setprecision(18).
//  - printf("%lld") on MinGW old: prefer cout.   YES/NO output: cout << (ok ? "YES" : "NO") << endl;
//  - grid input: vector<string> g(n); cin >> g;   (operator>> for vector is defined in [U1])
//  - 1-indexed arrays: vector<ll> a(n+1); for i=1..n cin>>a[i];
//  - memset(a,0x3f,sizeof a) for INF ints (~1.06e9); memset(a,-1,...) for -1; never memset vector objects.
//  - clear per-test containers!  Recursion depth > ~1e5: convert to iterative (Tarjan/TreeInfo above are iterative).

// ============================================================================
// [Z] CHEAT SHEET
// ----------------------------------------------------------------------------
// n limit -> complexity:  n<=10: n!  | <=20: 2^n*n or meet-in-middle(40) | <=500: n^3 | <=5000: n^2
//   <=1e5: n log^2 n | <=1e6: n log n | <=1e7: n | <=1e18: log n or sqrt n (number theory)
// Int limits: int 2.1e9, ll 9.2e18, ull 1.8e19.  a*b with a,b~1e9..1e18 -> mulmod/i128.  1e9+7 sums: add before %.
// Formulas: sum 1..n = n(n+1)/2 | sum squares = n(n+1)(2n+1)/6 | geometric (r^n-1)/(r-1)
//   C(n,k)=C(n-1,k-1)+C(n-1,k) | Catalan C(2n,n)/(n+1) | stars&bars C(n+k-1,k-1)
//   Fermat a^(p-1)=1 | inverse a^(p-2) | Euler a^phi(m)=1 (gcd=1) | a^e mod m, e huge: reduce e mod phi(m) (+phi if e>=log m)
//   Wilson (p-1)! = -1 mod p | CRT for coprime moduli | Burnside: #orbits = avg of fixed points
//   Inclusion-exclusion over subsets (2^k), Mobius: sum_{d|n} mu(d)=[n==1], gcd sums via phi: sum gcd(i,n) = sum_{d|n} d*phi(n/d)
//   Cayley: n^(n-2) labeled trees | Kirchhoff: det of Laplacian minor | Pick: A=I+B/2-1 | Euler V-E+F=2 (planar)
//   Hall's theorem, Konig (min vertex cover = max matching), Dilworth (min chain cover = max antichain)
//   Chicken McNugget (coprime a,b): largest unreachable = ab-a-b | harmonic sum n/1+n/2+...=O(n log n)
//   Number of divisors max ~1344 (<1e9), 103680 (<1e18).  Primes <1e6: 78498, <1e7: 664579, <1e9: 50847534.
//   XOR 0..n: n%4==0:n, 1:1, 2:n+1, 3:0 | a+b = (a^b) + 2(a&b) | lowbit x&-x | clear lowest: x&(x-1)
//   Modular negative: ((a%m)+m)%m | ceil(a/b) = (a+b-1)/b for positives | floor sqrt: use isqrt
// Pitfalls: signed overflow in 1<<k with k>=31 (use 1LL<<k) | size() unsigned: use sz() | unordered_map hacks: custom_hash
//   Dijkstra needs non-negative | Floyd needs INF guard | Mo's block sizing | uninitialised multi-test globals
//   Floating compare with EPS | print -0.0 | long double for precision | reading char vs string with spaces (getline)
//   Stack overflow in deep recursion on Windows (default 1MB!) -> iterative DFS / BFS-order DP.
// Strategy: brute force + small tests first, find pattern; think greedy/invariants; binary search the answer;
//   sort + two pointers; offline queries (sort by time / Mo / DSU); meet in the middle; bitmask; divide & conquer.
// ============================================================================

void Solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        Solve();
    }

    return 0;
}
