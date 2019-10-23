#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m;

int main() {
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m);
	vector<int> b(m);
	for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
	if (n < m) swap(a, b), n = m;
	b.resize(n);
	for (int i = 0; i < n; ++i) a[i] += b[i];
	a.push_back(0); n += 1;
	for (int i = n-1; i >= 0; --i) {
		if (i >= 3) {
			if (a[i] == 0 and a[i-1] == 2 and a[i-2] == 0 and a[i-3] == 0) 
				a[i] = 1, a[i-1] = 0, a[i-3] = 1;
			if (a[i] == 0 and a[i-1] == 2 and a[i-2] == 0 and a[i-3] == 1) 
				a[i] = 1, a[i-1] = 0, a[i-3] = 2;
		} 
		if (i >= 2) {
			if (i == 2 and a[i] == 0 and a[i-1] == 2 and a[i-2] == 0) 
				a[i] = 1, a[i-1] = 0, a[i-2] = 1;
			if (a[i] == 0 and a[i-1] == 1 and a[i-2] == 2) 
				a[i] = a[i-2] = 1, a[i-1] = 0;
		}
		if (i == 1 and a[i] == 0 and a[i-1] == 2) 
			a[i] = 1, a[i-1] = 0; 
	}
	for (int i = 0; i + 2 < n; ++i)
		if (a[i] == 1 and a[i+1] == 2 and a[i+2] == 0) 
			a[i] = 0, a[i+1] = a[i+2] = 1;
			
	a.push_back(0); n += 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) continue;
		int t = 1;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] == 1) t += 1;
			else break;
		} 
		if (t > 1) {
			if (t%2 == 0) {
				a[i] = 0;
				for (int j = 0; j < t; j += 2) {
					a[i + 1 + j] = 0;
					a[i + 2 + j] = 1;
				} 
			} else {
				a[i + 1] = 0;
				for (int j = 0; j < t-1; j += 2) {
					a[i + 2 + j] = 0;
					a[i + 3 + j] = 1;
				}
			}
		}
	}
	while (n >= 1 and a[n-1] == 0) a.pop_back(), n -= 1;
	cout << n << " ";
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
	cout << endl;
	return 0;
}
