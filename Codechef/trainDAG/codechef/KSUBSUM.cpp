#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4 + 10;
int A[maxN];
int T, N, K1, K2, K3;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &N, &K1, &K2, &K3);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", A+i);
            A[i] += A[i-1];
        }
        multiset<int> s, v;
        s.insert(0);
        for (int i = 1; i <= N; ++i) {
            for (int e : s) {
                if (v.size() < K3) {
                    v.insert(A[i] - e);
                } else {
                    if (A[i] - e < *v.begin()) break;
                    v.insert(A[i] - e);
                    v.erase(v.begin());
                }
            }
            s.insert(A[i]);
            if (s.size() > K3) {
                s.erase(s.lower_bound(*s.rbegin()));
            }
        }
        int it = 1;
        while (not v.empty()) {
            auto e = *v.rbegin();
            if (it == K1 or it == K2 or it == K3) {
                printf("%d ", e);
            }
            v.erase(v.lower_bound(*v.rbegin()));
            it += 1;
        }
        puts("");
    }
    return 0;
}
