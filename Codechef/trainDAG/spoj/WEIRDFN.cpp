#include <bits/stdc++.h>
using namespace std;
const int maxN = 200010;
priority_queue<int> A;
priority_queue<int, vector<int>, greater<int>> B; 
int m;
void add(int x) {
    m += 1;
    A.push(x);
    if (A.size() > (m+1) / 2) {
        B.push(A.top());
        A.pop();
    }
    if (not B.empty()) {
        if (A.top() > B.top()) {
            auto q = A.top(); A.pop();
            auto u = B.top(); B.pop();
            A.push(u);
            B.push(q);
        }
    }
}
 
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, n;
        scanf("%d %d %d %d", &a, &b, &c, &n);
        add(1);
        long long sum = 1;
        for (int i = 2; i <= n; ++i) {
            int x =  (a*1ll*A.top() + b*1ll*i + c)%1000000007;
            add(x);
            sum += x;
        }
        printf("%lld\n", sum);
        A = priority_queue<int>();
		    B = priority_queue<int, vector<int>, greater<int>>(); 
        m = 0;
    }
    return 0;
} 
