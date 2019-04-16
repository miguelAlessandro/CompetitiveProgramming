#include <bits/stdc++.h>
using namespace std;

priority_queue<int> A;
priority_queue<int, vector<int>, greater<int>> B;
int m;
void add(int x) {
    m += 1;
    A.push(x);
    while (A.size() > (m+1)>>1) {
        B.push(A.top());
        A.pop();
    }
    if (not B.empty()) {
        while (A.top() > B.top()) {
            auto u = A.top(); A.pop();
            auto v = B.top(); B.pop();
            A.push(v);
            B.push(u);
        }
    }
}
void erase() {
    m -= 1;
    A.pop();
    while (A.size() < ((m+1)>>1)) {
        A.push(B.top());
        B.pop();
    }
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        m = 0;
        A = priority_queue<int>();
        B = priority_queue<int, vector<int>, greater<int>>();
        while (scanf("%d", &n), n) {    
            if (n > 0) {
                add(n);     
            } else if (n == -1) {
                printf("%d\n", A.top());
                erase();
            }
        }
        puts("");
    }
    return 0;
}
