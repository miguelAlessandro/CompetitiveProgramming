#include <bits/stdc++.h>
using namespace std;
const int maxN = 8e3 + 10;
int a[3][maxN], pos[3][maxN];
int n;

bool dfs(int l1, int r1, int l2, int r2, int l3, int r3) {
	if (r1 - l1 != r2 - l2 or r1 - l1 != r3 - l3) return 0;	
	if (r1 <= l1) return 1;
	int prnt = a[0][l1];
	if (pos[0][prnt] != l1) return 0;
	if (pos[1][prnt] != r2) return 0;
	int len1 = pos[2][prnt] - l3;
	int len2 = r3 - pos[2][prnt];	
	return 	dfs(l1+1, l1+len1, l2, l2+len1-1, l3, l3+len1-1) and 
			dfs(l1+len1+1, r1, l2+len1, r2-1, l3+len1+1, r3);
}

int main() {
	scanf("%d", &n);
	for (int k = 0; k < 3; ++k) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a[k]+i);
			pos[k][a[k][i]] = i;
		}
	}
	puts(dfs(1, n, 1, n, 1, n)?"yes":"no");
	return 0;
}
