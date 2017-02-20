#include <bits/stdc++.h>
using namespace std;
 
long long n, m;
const long long mod = 1000000007;
 


inline void normal(long long& a) {
    a %= mod;
    (a < 0) && (a += mod);
}
 
inline long long mul(long long a, long long b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a * b) % mod;
}
 
inline long long add(long long a, long long b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a + b) % mod;
}
 
inline long long sub(long long a, long long b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
 
inline long long sum(long long n) { 
	return mul(mul(n, n + 1), (mod + 1) / 2); 
}

inline long long sum(long long lf, long long rg){
	 return sub(sum(rg), sum(lf - 1)); 
}
 
inline long long calcDiv(long long n, long long m) {
    m = min(m, n);
 
    long long ans = 0;
    long long minVal = m;
    for (long long i = 1; i * i <= n; i++) {
        long long lf = n / (i + 1), rg = n / i;
        rg = min(rg, m);
        if (lf >= rg) continue;
        minVal = lf; 
        ans = add(ans, mul(i, sum(lf + 1, rg)));
    }
    for(long long i = 1; i <= minVal; ++i)
        ans = add(ans, mul(n / i, i));
   
    return ans;
}
 
inline long long calcMod(long long n, long long m) {
    long long ans = mul(n, m);
    ans = sub(ans, calcDiv(n, m));
    return ans;
}
 
int t;

int main() {

	cin >> t;
 	while(t--){
   		cin >> n >> m;
    	cout  << calcMod(n, m) << endl;
    }
   
    return 0;
}
