/**
 *  @name Europe Junior Olympiad in Informatics 2017 - Borland
 *  @author Miguel Miní
 *  @tag probability, number thoery, d&c, monotone_stack
 *  @idea
 *    - Divide in logn blocks and solve independently each one,
 *    the probability. The probability that when maintaining 
 *    n / logn elements and the maximum is more than n / logn 
 *    elements is C (n, n / logn) / n! This is the same result 
 *    as in a treap. To cancel this result for very small numbers, 
 *    we use a fixed block length.
 *
 *    - We can also solve the problem with divide and conquer 
 *    by leading pointers for the two maxims we want.
 */

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, s, a, b, c;

int add(int a, int b) {
    return (a + b)%c;
}

int mul(long long a, long long b) {
    return a * b % c;
}

int ex(int a, int b) {
    int r = 1;
    while (b > 0) {
        if (b&1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

const int maxn = 2e5 + 2;
int arr[maxn];
int solve(int l, int r) {
    int inva = ex(a, c-2);
    int res = 0;
    int t = mul(add(s, c-b), inva);
    deque<pair<int, int>> p;
    for (int i = 1; i <= n; ++i) {
        t = add(mul(t, a), b);
        while (not p.empty() and p.back().second < t) p.pop_back();
        while (p.size() > maxn) p.pop_front();
        if (l <= i and i <= r) {
            if (not p.empty()) arr[i-l] = p.back().first + 1;
            else arr[i-l] = 1;
        }
        p.push_back({i, t});
    }
    while (not p.empty()) p.pop_back();
    t = add(mul(t, a), b);
    for (int i = n; i >= 1; --i) {
        t = mul(add(t, c-b), inva);
        while (not p.empty() and p.back().second <= t) p.pop_back();
        while (p.size() > maxn) p.pop_front();
        if (l <= i and i <= r) {
            if (not p.empty()) res = (res + t*1ll*(i - arr[i-l] + 1)%mod*(p.back().first - i))%mod;
            else res = (res + t*1ll*(i - arr[i-l] + 1)%mod*(n - i + 1))%mod;
        }
        p.push_back({i, t});
    }
    return res;
}



int main() {
    cin >> n >> s >> a >> b >> c;
    int res = 0;
    for (int i = 1; i <= n; i += maxn) {
        res = (res + solve(i, min(n, i + maxn-1)))%mod;
    }
    cout << res << endl;
    return 0;
}
