/**
 *	@name CEOI 2016 router
 *	@author Miguel Mini
 *	@tag constructive
 *	@idea
 *		- connect with B-blocks
 *		every input and output nodes
 *		
 *		- connect every input S-B-block
 *		with every output S-B-block with
 *		an intermediate node.
 *
 *		- we can select B = 10 and S = 31.
 */

#include <bits/stdc++.h>
using namespace std;
int N, M;

int get_new() {
	return ++M;
}

int main() {
	cin >> N; M = 2*N;	
	vector<pair<int, int>> edges;
	vector<int> t1, t2;
	int n1, n2;
	for (int i = 1; i <= N; i += 10) { 
		n1 = get_new();
		n2 = get_new();
		t1.push_back(n1);
		t2.push_back(n2);
		for (int j = 0; j < 10 and i + j <= N; ++j) {
			edges.push_back({i+j, n1});
			edges.push_back({n2, N+i+j});
		}
	}
	int n3;
	for (int i = 0; i < t1.size(); i += 31) {
		for (int j = 0; j < t2.size(); j += 31) {
			n3 = get_new();
			for (int k = 0; k < 31 and i + k < t1.size(); ++k) {
				edges.push_back({t1[i+k], n3});
			}	
			for (int k = 0; k < 31 and j + k < t2.size(); ++k) {
				edges.push_back({n3, t2[j+k]});
			}
		}
	}
	cout << M << " " << edges.size() << endl;
	for (auto e : edges) {
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}
