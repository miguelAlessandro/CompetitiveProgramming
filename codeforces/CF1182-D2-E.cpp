/**
 *	@author Codeforces 1182 Div2 E
 *	@name Miguel Mini
 *	@tag matrix_multiplication
 *	@idea
 *		- this is a simple matrix problem
 *		over exponents.
 *		- look the code for matrix relation.
**/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int add(int a, int b, int m) {
	return (a + b) % m;	
}

int mul(long long a, long long b, int m) {
	return a * b % m;
}

int ex(int a, int b, int m) {
	int r = 1;
	while (b > 0) {
		if (b & 1) r = mul(r, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return r;
}

struct Matrix {
	vector<vector<int>> at;	
	Matrix(int n): at(n, vector<int>(n)) {}
	void one() {	
		for (int i = 0; i < at.size(); ++i) {
			for (int j = 0; j < at.size(); ++j) {
				at[i][j] = i==j;
			}
		}
	}
	Matrix operator *(Matrix X) {
		int n = X.at.size();
		Matrix R(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					R.at[i][j] = add(R.at[i][j], 
							mul(at[i][k], X.at[k][j], MOD-1), MOD-1);
				}	
			}
		}
		return R;
	}
	friend Matrix ex(Matrix A, long long T) {
		int n = A.at.size();
		Matrix R(n);
		R.one();
		while (T > 0) {
			if (T&1) R = R * A;
			A = A * A;
			T >>= 1;
		}
		return R;
	}
};

int main() {
	long long n;
	int f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	Matrix C(5);
	C.at = {
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{1, 1, 1, 2, MOD-7},
		{0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1}
	};
	Matrix F(3);
	F.at = {
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1}
	};
	int ans = 1;
	if (n >= 4) {
		C = ex(C, n-3);			 
		vector<int> p = {0, 0, 0, 4, 1};
		int temp = 0;
		for (int i = 0; i < 5; ++i) {
			temp = add(temp, mul(C.at[2][i], p[i], MOD-1), MOD-1);
		}
		ans = mul(ans, ex(c, temp, MOD), MOD);
	}
	F = ex(F, n-1);
	ans = mul(ans, ex(f1, F.at[0][0], MOD), MOD);
	ans = mul(ans, ex(f2, F.at[0][1], MOD), MOD);
	ans = mul(ans, ex(f3, F.at[0][2], MOD), MOD);
	cout << ans << endl;
	return 0;
}
