#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector<long long> m[N], bf[N][N];
int n;

long long backtracking(int i, vector<long long>& v){
	if(i == 0){
		long long maxi = 0;
		for(int j = 0; j < n; ++j)
			maxi = max(maxi, v[j]);
		return maxi;
	}
	
	long long r = LLONG_MAX;
	for(int j = 0; j < n; ++j){
		for(int k = 0; k < n; ++k) v[k] += bf[i-1][j][k];	
		r = min(r, backtracking(i-1, v));
		for(int k = 0; k < n; ++k) v[k]	-= bf[i-1][j][k];
	}
	return r;
}


int main(){

	while(scanf("%d", &n), n!=-1){
	
		for(int i = 0; i < n; ++i){
			m[i].reserve(n);
			for(int j = 0; j < n; ++j)
				scanf("%lld", &m[i][j]);		
		}		
		vector<long long> t(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				for(int k = 0; k < n; ++k)
					t[k] = m[i][(k+j)%n];
				bf[i][j] = t;
			}
		
		long long mini = LLONG_MAX;
		for(int i = 0; i < n; ++i)
			mini = min(mini, backtracking(n-1, bf[n-1][i]));
		printf("%lld\n", mini);
	}

	return 0;
}
