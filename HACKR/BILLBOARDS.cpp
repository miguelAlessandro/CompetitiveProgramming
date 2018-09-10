/**
 *  HACKERRANK - BILLBOARDS
 *  @overview maximum array sum with consecutives (<=k length)-blocks  
 *  - hint: if I consider active range of dp, dp is solution to problem [0,i] y without element i+1.  
 *  - if dp[i] is active then, mi solution is maximize with dp[i] + a[i+1] + a[i+2] + ... + a[j] 
 *  = dp[i] + (a[i+1] + ... + a[n]) - (a[j+1] + a[j+2] + ... + a[n]).
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e5;
ll dp[MAX_N], L[MAX_N], R[MAX_N], add[MAX_N];
int value[MAX_N];
int n, k;

int main () {
    
    scanf ("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", value+i);
    }
    for (int i = 1; i <= n; ++i) {
        L[i] = L[i-1] + value[i];
    }
    for (int i = n; i >= 1; --i) {
        R[i] = R[i+1] + value[i];
    }
    
    multiset<ll, greater<ll>> Set; 
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) { 
        add[i] = dp[i-1] + L[n] - L[i-1];
        Set.insert(add[i]);        
        if (Set.size() > k) {
            Set.erase(Set.lower_bound(add[i-k]));
        }
        dp[i+1] = *(Set.begin()) - R[i+1];
    }
    
    printf("%lld\n", dp[n+1]);
    return 0;
}
