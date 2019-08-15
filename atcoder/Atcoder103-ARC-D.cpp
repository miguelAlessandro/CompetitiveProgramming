#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
typedef long long llong;
vector<llong> d; 
int x[maxN], y[maxN];
int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char C[] = {'L', 'R', 'D', 'U'};

bool valid(llong x, llong y, int k) {
	return abs(x) + abs(y) <= (1ll<<k) - 1;
}

string get(int pos, llong x, llong y) {
	if (pos == -1) return "";
	for (int i = 0; i < 4; ++i) {
		llong nx = x + dx[i] * d[pos];
		llong ny = y + dy[i] * d[pos];
		int f = (x+y&1) != (nx+ny&1);
		if (d[pos] == f or (f == 0 and d[pos] != 1))	
		if (valid(nx, ny, pos)) {
			return get(pos-1, nx, ny) + C[i^1];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i < n; ++i) {
		if ((x[i] + y[i]&1) != (x[i+1] + y[i+1]&1)) {
			puts("-1");
			return 0;
		}
	}
	for (int t = 0; t <= 30; ++t) {
		d.push_back(1ll<<t);
	}
	if (((x[1] + y[1])&1) == 0) d.push_back(1);
	cout << d.size() << endl;
	for (int e : d) cout << e << " "; cout << endl;
	for (int i = 1; i <= n; ++i) {
		cout << get((int)d.size() - 1, x[i], y[i]) << endl;
	}
	return 0;
}
