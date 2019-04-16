#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &k, &n);
        priority_queue<int, vector<int>, greater<int>> Q;
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            Q.push(x);
            if (Q.size() > k) Q.pop();
            if (Q.size() < k) printf("-1 ");
            else printf("%d ", Q.top());
        }
        puts("");
    }
    return 0;
}
