#include <bits/stdc++.h>
using namespace std;

priority_queue<int> A;
priority_queue<int, vector<int>, greater<int>> B;
int m = 0;
void add(int x) {
    m += 1;
    int e = m / 3;
    B.push(x);
    if (B.size() > e) {
        A.push(B.top());
        B.pop();
    }
    if (e) {
        if (B.top() < A.top()) {
            auto q = A.top(); A.pop();
            auto u = B.top(); B.pop();
            A.push(u);
            B.push(q);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 2) {
            if (B.empty()) puts("No reviews yet");            
            else printf("%d\n", B.top());
        }
        else {
            int x;
            scanf("%d", &x);
            add(x);
        }
    }
    return 0;
}
