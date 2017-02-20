/**********************
round: 397
handle: _threat_
theme: math, greedy
complexity: O(n)
**********************/

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, t=1, m=1, g[N], f[N], h[N];
bool ok=true;

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d", f+i);
		if(f[i]==i){ g[h[m]=i] = m; m++;}
		ok &= f[f[i]] == f[i];
	} m--;

	if(m*ok) puts("-1");
	else{
		printf("%d\n", m);
	
		for(int i = 1; i <= n; ++i)
			printf("%d ", g[f[i]]); puts("");
	
		for(int i = 1; i <= m; ++i)
			printf("%d ", h[i]); puts("");
	}

	return 0;
}
