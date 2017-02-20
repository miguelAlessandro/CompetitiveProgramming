#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int n, m;
int pos[N];
long long sum;

int main(){

	scanf("%d %d", &n, &m);
	for(int x, i = 1; i <= n; ++i){
		scanf("%d", &x);
		pos[x] = i;
	}

	for(int x, y, a, b, i = 1; i <= m; ++i){
		scanf("%d %d", &a, &b);
		x = min(pos[a], pos[b]);
		y = max(pos[a], pos[b]);
		sum += x*(n-y+1);
	}


	printf("%lld\n", n*(n-1)/2 - sum);


	return 0;
}
