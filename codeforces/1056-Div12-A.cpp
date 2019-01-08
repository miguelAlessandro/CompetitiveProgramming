/**
 * Determine line
 * @author Miguel Mini
 * @tag ad-hoc
 * @idea this is a simple ad-hoc problem
 *
 *
 */


#include <bits/stdc++.h>
using namespace std;
int cnt[102];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int x;
			scanf("%d", &x);
			cnt[x] += 1;
		}
	}
	for (int i = 1; i <= 100; ++i) {
		if (cnt[i] == n) {
			cout << i << " ";
		}
	} 
	cout << endl;
	return 0;
}
