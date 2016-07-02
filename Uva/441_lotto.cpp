#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > solve;
vector<int> s;
int n, nc;

void backtracking(vector<int>& v, int it){

	int l = v.size();
	if(l == 6){ 
		for(int j = 0; j < l; ++j)
			printf("%d%c", v[j], j+1 == l ? '\n' : ' ');
		return;		
	}
	
	for(int i = it; i < n-5+l; ++i){
		v.push_back(s[i]);
		backtracking(v, i+1);
		v.pop_back();
	}
}


int main() {
	
	while(scanf("%d", &n), n){
		s.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &s[i]);
			
		vector<int> v;
		if(nc++) putchar('\n');
		backtracking(v, 0);
	}
	
	return 0;
}
