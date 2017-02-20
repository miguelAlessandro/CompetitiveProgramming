#include <bits/stdc++.h>
using namespace std;


int n, m;

int main(){

	cin >> n >> m;
	int maxt = 1;
	for(int i = 0; i < n; ++i){
		int minrow = INT_MAX;
		for(int x, j = 0; j < m; ++j){
			cin >> x;
			minrow = min(minrow, x);
		}	
		maxt = max(maxt, minrow);
	}

	cout << maxt << endl;


	return 0;
}
