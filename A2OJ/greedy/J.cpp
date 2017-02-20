#include <bits/stdc++.h>
using namespace std;

long long n, m;
int t, nc=1;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &n, &m);
		printf("Case %d: %lld\n", nc++, (n-1)/m);
	}

	return 0;
}
