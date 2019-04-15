#include <bits/stdc++.h>
using namespace std;
const int maxN = (1<<15) + 10;
int A[maxN];
int T, N;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 1<<N; ++i) {
            cin >> A[i];
        }
        sort(A, A+(1<<N));
        for (int i = 0; i < N; ++i) {
            int x = A[1];
            cout << x << " ";
            priority_queue<int> Q;
            vector<int> nxt;
            for (int j = (1<<N-i) - 1; j >= 0; --j) {
                if (Q.empty() or A[j] != Q.top()) Q.push(A[j] - x);
                else if (A[j] == Q.top()) Q.pop(), nxt.push_back(A[j]);
            } 
            reverse(begin(nxt), end(nxt));
            for (int j = 0; j < nxt.size(); ++j) {
                A[j] = nxt[j];
            }
        }
        cout << endl;
    }
    return 0;
}
