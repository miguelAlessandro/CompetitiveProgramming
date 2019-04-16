#include <bits/stdc++.h>
using namespace std;
const int maxN = 50010;
vector<int> g[maxN];
int p[maxN];
int n, t;

class cmp {
    public:
    bool operator()(int x, int y) {  
        return p[x] < p[y];
    }
};

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            g[i].emplace_back(i);
        }
        priority_queue<int, vector<int>, cmp> Q;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", p+i);
            Q.push(i);
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            sort(rbegin(g[i]), rend(g[i]), cmp());
        }
        for (int i = 1; i <= n; ++i) {
            vector<int> temp;
            for (int v : g[i]) {
                if (v == Q.top()) {
                    temp.emplace_back(v);
                    Q.pop();
                }
            }
            if (Q.empty()) printf("0 ");
            else printf("%d ", Q.top());
            for (int e : temp) Q.push(e);
        }
        puts("");
    }
    return 0;
}
