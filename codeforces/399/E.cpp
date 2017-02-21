#include <bits/stdc++.h>
using namespace std;

const int N = 65;
int n, r;
int gn[N];

int main(){
	
	scanf("%d", &n);

	int s = 1, t = 1;
	for(int i = 2; i <= 11; ++i){
		for(int j = 0; j < i and s+j < N; ++j) gn[s+j] = t;
		s += i; if(s >= N) break;
		t++;	
	}

	for(int x, i = 0; i < n; ++i){
		scanf("%d", &x);
		r ^= gn[x];
	}

	puts(r ? "NO" : "YES");

	return 0;
}
