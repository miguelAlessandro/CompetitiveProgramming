#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
queue<pair<int, int>> g[maxN];
int T, N, D;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> D;
        priority_queue<pair<int, int>> Q;
        long long sum = 0;
        for (int i = 1; i <= N; ++i) {
            int d, t, s;
            cin >> d >> t >> s;
            g[d].emplace(s, t);
            sum += s *1ll* t; 
        }
        for (int i = 1; i <= D; ++i) {
            while (not g[i].empty()) {
                Q.push(g[i].front());
                g[i].pop();
            }
            if (Q.empty()) continue;
            auto q = Q.top(); Q.pop();
            sum -= q.first;
            q.second -= 1;
            if (q.second) {
                Q.push(q);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
