#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
string s[maxN];
pair<string, int> label[maxN];
int st[maxN<<2];
int n;

void build(int nx=1, int l=0, int r=n-1) {
	if (l == r) {
		st[nx] = r;
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);	
	build(nx<<1|1, mid+1, r);
	if (label[st[nx<<1]].second < label[st[nx<<1|1]].second) st[nx] = st[nx<<1|1];
	else st[nx] = st[nx<<1];
}

int query(int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return -1;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;	
	int L = query(ll, rr, nx<<1, l, mid);
	int R = query(ll, rr, nx<<1|1, mid+1, r);
	if (R == -1) return L;
	if (L == -1 or label[L].second < label[R].second) return R;
	return L;
}

void makeTreap(int l=0, int r=n-1) {
	if (r < l) return;
	cout << "(";	
	if (l == r) {
		cout << label[r].first << "/" << label[r].second;
	} else {
		int mid = query(l, r);
		makeTreap(l, mid-1);
		cout << label[mid].first << "/" << label[mid].second;
		makeTreap(mid+1, r);
	}
	cout << ")";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>n, n) {
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			bool t = 0;
			label[i] = {"", 0};
			for (auto e : s[i]) {
				if (t == 0) {
					if (e == '/') t = 1;
					else label[i].first += e;
					continue;
				} else label[i].second = (label[i].second<<3) + (label[i].second<<1) + e - '0';
			}		
		}
		sort(label, label+n, [](pair<string, int>& x, pair<string, int>& y) {
			return x < y;
		});
		build();
		makeTreap(); cout << endl;
	}
	return 0;
}
