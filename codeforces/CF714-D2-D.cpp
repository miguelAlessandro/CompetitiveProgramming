#include <bits/stdc++.h>
using namespace std;

int query(int x_1, int y_1, int x_2, int y_2) {
	cout << "? " << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << endl;
	int x;
	return cin >> x, x;
}

int getR(int x_1, int y_1, int x_2, int y_2, int t) {
	int lo = x_1, hi = x_2;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (query(x_1, y_1, mid, y_2) < t) lo = mid+1;
		else hi = mid; 
	}
	return query(x_1, y_1, lo, y_2) == t ? lo : -1;
} 

int getL(int x_1, int y_1, int x_2, int y_2, int t) {
	int lo = x_1, hi = x_2;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (query(mid, y_1, x_2, y_2) >= t) lo = mid;
		else hi = mid-1; 
	}
	return query(lo, y_1, x_2, y_2) == t ? lo : -1;
}
 
int getU(int x_1, int y_1, int x_2, int y_2, int t) {
	int lo = y_1, hi = y_2;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (query(x_1, y_1, x_2, mid) < t) lo = mid+1;
		else hi = mid; 
	}
	return query(x_1, y_1, x_2, lo) == t ? lo : -1;
} 

int getD(int x_1, int y_1, int x_2, int y_2, int t) {
	int lo = y_1, hi = y_2;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (query(x_1, mid, x_2, y_2) >= t) lo = mid;
		else hi = mid - 1; 
	}
	return query(x_1, lo, x_2, y_2) == t ? lo : -1;
} 

vector<int> solve(int x_1, int y_1, int x_2, int y_2) {
	vector<int> e;
	e.push_back(getL(x_1, y_1, x_2, y_2, 1));
	e.push_back(getD(x_1, y_1, x_2, y_2, 1));
	e.push_back(getR(x_1, y_1, x_2, y_2, 1));
	e.push_back(getU(x_1, y_1, x_2, y_2, 1));
	return e;
}

int main() {
	int n;
	cin >> n;	
	int pos = getU(1, 1, n, n, 1);
	vector<int> u, v;
	if (pos != -1 and (query(1, 1, n, pos) == 1 and 1 == query(1, pos+1, n, n))) {
		u = solve(1, 1, n, pos);
		v = solve(1, pos+1, n, n);
	} else {
		pos = getR(1, 1, n, n, 1);
		u = solve(1, 1, pos, n);
		v = solve(pos+1, 1, n, n);
	}
	cout << "!";
	for (int e : u) cout << " " << e;
	for (int e : v) cout << " " << e;
	cout << endl;
	return 0;
}
