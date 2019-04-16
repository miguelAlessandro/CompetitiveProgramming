#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int t, n;
int a[maxN], b[maxN], d[maxN];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        double sum = 0;
        vector<pair<int, int>> v;
        v.emplace_back(0, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", a+i, b+i, d+i);
            sum += 1.d * b[i] / a[i];
            v.emplace_back(d[i], i);
        }
        sort(begin(v), end(v));
        int i = (int)v.size() - 1;
        int last = v.back().first;
        typedef pair<int, double> pid;
        priority_queue<pid, vector<pid>, greater<pid>> Q;
        while (i >= 1) {
            while (i >= 1 and v[i].first == last) {
                Q.emplace(a[v[i].second], b[v[i].second]);
                i -= 1;
            }
            double cur = last;
            while (not Q.empty() and cur > v[i].first + 1e-10) {
                auto q = Q.top(); Q.pop();
                if (cur - q.second >= v[i].first) {
                    cur -= q.second;
                    sum -= q.second / q.first;
                } else {
                    double diff = cur - v[i].first;
                    cur = v[i].first;
                    q.second -= diff;
                    sum -= diff / q.first;
                    if (q.second > 1e-10) Q.push(q); 
                }
            }
            last = v[i].first;
        }
        printf("%lf\n", sum);
    }
    return 0;
}
