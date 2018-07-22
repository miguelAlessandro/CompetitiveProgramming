#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MAX_N = 1e3 + 5;
bool M[3][MAX_N];
int memo[3][MAX_N];
int t, n;

int add (int a, int b) {
	return  (a + b) % mod;
}

int main () {

	scanf ("%d", &t);
	int nc = 1;
	while (t --) {

		scanf ("%d\n", &n);

		for (int i = 0; i < 3; ++i) {
			for (int j = 1; j <= n; ++j)
				M[i][j] = getchar() == '.';
			getchar();
		}

		if (n&1) {
			printf ("Case #%d: 0\n", nc++);
			continue;
		}

		M[0][0] = 1;
		M[1][0] = 0;
		M[2][0] = 0;

		memset (memo, 0, sizeof memo);
		
		memo[0][0] = 1;
		memo[1][0] = 0;
		memo[2][0] = 0;

		for (int i = 1; i <= n; ++i) {

			if (i&1) {
				if (M[1][i]) {
					if (M[0][i]) memo[1][i] = add(memo[1][i], memo[0][i-1]);
					if (M[2][i]) memo[1][i] = add(memo[1][i], memo[2][i-1]);
				}
			} else {
				if (M[1][i]) {
					if (M[0][i]) memo[0][i] = add(memo[0][i], memo[1][i-1]);
					if (M[2][i]) memo[2][i] = add(memo[2][i], memo[1][i-1]);
				}
			}	
		}

		printf ("Case #%d: %d\n", nc++, memo[2][n]);
	}
	

	return 0;
}
