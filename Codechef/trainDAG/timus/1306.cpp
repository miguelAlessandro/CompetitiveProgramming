#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int mid = (1<<31)-1;
    priority_queue<int> Q;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        Q.push(x);
        if (Q.size() > (n>>1)) {
            mid = min(mid, Q.top());
            Q.pop();
        }
    }
    if (n&1) printf("%d.0\n", mid);
    else printf("%.1f\n", (0. + Q.top() + mid) / 2.);
    return 0;
}
