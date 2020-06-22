/**
 * @name 1b taming a bomb
 * @author Miguel Mini
 * @tag greedy
 * @idea
 *		- suppose the following sequence 
 *		[1, ..., (n+1)//2][(n+1)//2, ..., 1]
 *      [(n+1)/2+1, ..., n][n, ..., (n+1)/2+1]
 *		[1, ..., (n+1)//2][(n+1)//2, .., 1]
 *	
 *		- if x is in the range [1, ..., (n+1)//2]
 *		can by detected with range 2 or 6, in other 
 *		case with range 4 and 5.
 */

#include <bits/stdc++.h>
using namespace std;
int bips;
int n;

int xx = 0;
//brute force to all valid candidates
int check(vector<int>& f, vector<int>& g, int l, int r) {
	int times = 0;
	for (int k = 0; k < n; ++k) {
		for (int i = l; i <= r; ++i) {
			bool fun = 1;
			for (int j = 0; j < g.size(); ++j) {
				if (g[j] == i and j + k < g.size() and f[j+k] != 1) {
					fun = 0;
				}
				if (f[j] == 1 and (j < k or g[j - k] != i)) {
					fun = 0;
				}
			}
			if (fun) xx = i;
			times += fun;
		}
	}
	return times;
}

int find() {
	string s;
	vector<int> f, g;
	int l = 1, r = (n+1)/2;
	for (int i = l; i <= r; ++i) {
		if (check(f, g, 1, n) == 1 and bips) return xx;
		cout << i << endl;
		cin >> s;	
		g.push_back(i);
		if (s == "BIP") f.push_back(1), bips += 1;
		else f.push_back(0);
	}
	for (int i = r; i >= l; --i) {
		if (check(f, g, 1, n) == 1 and bips) return xx;
		cout << i << endl;
		cin >> s;
		g.push_back(i);
		if (s == "BIP") f.push_back(1), bips += 1;
		else f.push_back(0);
	}
	l = r+1; r = n;
	for (int i = l; i <= r; ++i) {
		if (check(f, g, 1, n) == 1 and bips) return xx;
		cout << i << endl;
		cin >> s;	
		g.push_back(i);
		if (s == "BIP") f.push_back(1), bips += 1;
		else f.push_back(0);
	}
	for (int i = r; i >= l; --i) {
		if (check(f, g, 1, n) == 1 and bips) return xx;
		cout << i << endl;
		cin >> s;
		g.push_back(i);
		if (s == "BIP") f.push_back(1), bips += 1;
		else f.push_back(0);
	}
	l = 1; r = (n+1)/2;	
	for (int i = l; i <= r; ++i) {
		if (check(f, g, 1, n) == 1 and bips) return xx;
		cout << i << endl;
		cin >> s;	
		g.push_back(i);
		if (s == "BIP") f.push_back(1), bips += 1;
		else f.push_back(0);
	}
	for (int i = r; i >= l; --i) {
		if (check(f, g, 1, n) == 1 and bips) return xx;
		cout << i << endl;
		cin >> s;
		g.push_back(i);
		if (s == "BIP") f.push_back(1), bips += 1;
		else f.push_back(0);
	}
	if (check(f, g, 1, n) == 1 and bips) return xx;
}

int main() {
	string s;
	cin >> s;
	int t, r;
	cin >> n >> t >> r;
	int m = n/2;
	int x = find();
	while (bips < n) {
		cout << x << endl;
		cin >> s;
		if (s == "BIP") bips += 1;
	}
	return 0;
}
