#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
int g[maxN];
int t, N;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        priority_queue<int> Q;
        memset(g, 0, sizeof g);
        for (int i = 1; i <= N; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            g[a] += b; 
        }
        int L, P;
        scanf("%d %d", &L, &P);
        bool ok = 1;
        int ans = 0;
        for (int i = L; i >= 1; --i) {
            if (g[i]) {
                Q.push(g[i]);
            }
            while (not Q.empty() and P <= 0) {
                P += Q.top();
                ans += 1;
                Q.pop();
            }
            if (P <= 0) {
                ok = 0;
                break;
            }
            P -= 1;
        }
        if (ok) printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}
