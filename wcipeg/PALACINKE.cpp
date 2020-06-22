/**
 *	@name PALACINKE
 *	@author Miguel Mini
 *	@tags matrix-multiplication, IEP
 *	@idea:
 *		- use IEP to transform in opposite problem,
 *		- add edge 0 to dummy node to count for every time.
 */

#include <bits/stdc++.h>
#define f(x, y, z) for (int x = y; x < z; ++x)
using namespace std;
const int mod = 5557;
typedef long long llong;

int add(int a, int b) {
	return (a+b)%mod;
}

int mul(int a, int b) {
	return a*b%mod;
}

struct Matrix {
	vector<vector<int>> t;

	Matrix(int n, bool type=0) {
		t.resize(n, vector<int>(n));
		f(i, 0, n)
			f(j, 0, n)
				t[i][j] = (i == j) & type;
	}

	Matrix operator *(const Matrix& X) {
		int n = t.size();
		Matrix R(n);
		f(i, 0, n)
			f(j, 0, n)
				f(k, 0, n)
					R.t[i][j] = add(R.t[i][j], 
						mul(t[i][k], X.t[k][j]));	
		return R;
	}
};

Matrix exp(Matrix A, int m) {
	Matrix R(A.t.size(), 1);
	while (m > 0) {
		if (m&1) R = R * A;
		A = A * A;
		m >>= 1;
	}
	return R;
}

int main() {
	int n, m, t;
	map<char, int> T; 
	T['B'] = 0;
	T['J'] = 1;
	T['M'] = 2;
	T['P'] = 3;
	cin >> n >> m;	
	vector<pair<pair<int, int>, int>> edges; 
	for (int i = 1; i <= m; ++i) {
		int u, v;
		string s;
		cin >> u >> v >> s;
		--u; --v;
		int mask = 0;
		for (char c : s) mask |= 1<<T[c];
		edges.push_back({{u, v}, mask});
	}
	cin >> t;
	int ans = 0;
	for (int mask = 0; mask < 1<<4; ++mask) {	
		Matrix A(2*n + 1);
		for (auto e : edges) {		
			A.t[e.first.first][e.first.second] = 1;
			if ((e.second & mask) == 0) { 
				A.t[e.first.first][n + e.first.second] = 1;
				A.t[n + e.first.second][e.first.second] = 1; 
			}
		}
		A.t[0][2*n] = A.t[2*n][2*n] = 1;
		A = exp(A, t+1);
		if (__builtin_popcount(mask) & 1) ans = add(ans, mod - A.t[0][2*n]);
		else ans = add(ans, A.t[0][2*n]);
	}
	printf("%d\n", ans);
	return 0;
}
