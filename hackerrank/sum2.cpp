#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
li n, m;
 
inline bool read() {
    return !!(cin >> n >> m);
}
 
const li mod = INF + 7;
 
inline void normal(li& a) {
    a %= mod;
    (a < 0) && (a += mod);
}
 
inline li mul(li a, li b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a * b) % mod;
}
 
inline li add(li a, li b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a + b) % mod;
}
 
inline li sub(li a, li b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
 
inline li sum(li n) { return mul(mul(n, n + 1), (mod + 1) / 2); }
inline li sum(li lf, li rg) { return sub(sum(rg), sum(lf - 1)); }
 
inline li calcDiv(li n, li m) {
    m = min(m, n);
 
    li ans = 0;
    li minVal = m;
    for (li i = 1; i * i <= n; i++) {
        li lf = n / (i + 1), rg = n / i;
        rg = min(rg, m);
        if (lf >= rg) continue;
        minVal = lf; // interval (lf, rg]
        ans = add(ans, mul(i, sum(lf + 1, rg)));
    }
    fore(i, 1, minVal + 1) {
        ans = add(ans, mul(n / i, i));
    }
    return ans;
}
 
inline li calcMod(li n, li m) {
    li ans = mul(n, m);
    ans = sub(ans, calcDiv(n, m));
    return ans;
}
 
inline void solve() {
    cout << calcMod(n, m) << endl;
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        solve();
        //break;
    }
    cerr << clock() / ld(CLOCKS_PER_SEC) << endl;
   
    return 0;
}
