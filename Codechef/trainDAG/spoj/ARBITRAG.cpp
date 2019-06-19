#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, nc=1;
	while (cin >> n, n) {
		cout << "Case " << nc++ << ": ";
		double dis[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dis[i][j] = 1e9;
			}
		}
		for (int i = 0; i < n; ++i) dis[i][i] = 0;
		string s;
		map<string, int> pos;
		for (int i = 0; i < n; ++i) pos[cin >>s, s] = i;
		int m; cin >> m;
		for (int i = 0; i < m; ++i) {
			string A, B; double cst;
			cin >> A >> cst >> B;
			dis[pos[A]][pos[B]] = log(cst);
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = max(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		bool ans = 0;
		for (int i = 0; i < n; ++i) ans |= dis[i][i] > 0;
		puts(ans ? "Yes" : "No");
	}
	return 0;
}
