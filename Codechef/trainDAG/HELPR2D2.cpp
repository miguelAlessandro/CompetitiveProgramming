#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int st[maxN<<2];
int t, k, n;

void build(int nx=1, int l=0, int r=100000) {
	if (l == r) {
		st[nx] = k;
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = max(st[nx<<1], st[nx<<1|1]);
}

int cnt;
void qry(int v, int nx=1, int l=0, int r=100000) {
	if (l == r) {
		if (st[nx] == k) cnt += 1;
		st[nx] -= v;
		return;
	}
	int mid = (l+r)/2;
	if (st[nx<<1] >= v) qry(v, nx<<1, l, mid);
	else qry(v, nx<<1|1, mid+1, r);
	st[nx] = max(st[nx<<1], st[nx<<1|1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> k >> n;
		build();
		cnt = 0;
		int sum = 0;
		cin.ignore();
		while (1) {
			string line;
			getline(cin, line);	
			int c, v;
			if (line[0] == 'b') {
				istringstream in(line.substr(2));
				in >> c >> v;
			} else {	
				istringstream in(line);
				c = 1; 
				in >> v;
			}
			sum += c * v;
			for (int i = 0; i < c; ++i) {
				qry(v);
			}
			n -= c;
			if (n == 0) break;
		}		
		cout << cnt << " " << k * cnt - sum << endl;
	}
	return 0;
}
