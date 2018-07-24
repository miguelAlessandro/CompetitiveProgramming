#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4e4 + 10;
int st[MAX_N<<2];
int lazy[MAX_N<<2];
int dp[55][MAX_N];
int n,k;
int a[MAX_N];

void build () {
	memset(st, 0, sizeof st);
	memset(lazy, 0, sizeof lazy);
}

int merge(int a, int b) {
	return max(a, b);
}

void upd (int nx, int c) {
	lazy[nx] += c;
	st[nx] += c;
} 

void push(int nx) {
	if (lazy[nx]) {
		upd(2*nx, lazy[nx]);
		upd(2*nx+1, lazy[nx]);
		lazy[nx] = 0;
	}
}

void update (int a, int b, int c, int nx = 1, int l =  1, int r = n) {
	if (a > r or b < l) return;
	if (a <= l and r <= b) {
		upd(nx, c);
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	update(a, b, c, 2*nx, l, mid);
	update(a, b, c, 2*nx+1, mid+1, r);
	st[nx] = merge(st[2*nx], st[2*nx+1]);
}

int query (int a, int b, int nx = 1, int l = 1, int r = n) {
	if (a > r or b < l) return 0;	
	if (a <= l and r <= b) return st[nx];
	int mid = (l+r)/2;
	push(nx);
	int L = query(a, b, 2*nx, l, mid);
	int R = query(a, b, 2*nx+1, mid+1, r);
	st[nx] = merge(st[2*nx], st[2*nx+1]);
	return merge(L, R);
}


int main () {

	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", a+i);

	set<int> Set;
	for (int i = 1; i <= n; ++i) {
		Set.insert(a[i]);
		dp[1][i] = Set.size();
	}

	map<int, int> id;
	for (int i = 2; i <= k; ++i) {
		
		build();		
		id.clear();
		update(i-1, i-1, dp[i-1][i-1]); 
		
		for (int j = i; j <= n; ++j) {
			update(max(i-1, id[a[j]]), j-1, 1);
			dp[i][j] = query(i-1, j-1);
			id[a[j]] = j;
			update(j, j, dp[i-1][j]);
		}
	}	

	printf ("%d\n", dp[k][n]);
	return 0;
}
