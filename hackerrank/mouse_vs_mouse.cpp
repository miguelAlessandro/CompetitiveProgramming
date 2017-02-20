#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int n;

long long expfast(long long a, long long n){
	long long r = 1;
	while(n > 0){
		if(n&1LL) r = (r*a)%MOD;
		a = (a*a)%MOD;
		n >>= 1;
	}
	return r;
}

int main(){

	scanf("%d", &n);
	int c = 0;
	for(int x, i = 0; i < n; ++i){
		scanf("%d", &x);
		if(x%2 == 0) c++;	
	}

	if(c != n)
		printf("%lld\n", ((expfast(2, n-1) - 1)%MOD + MOD)%MOD);
	else 
		printf("%lld\n", ((expfast(2, n) - 1)%MOD + MOD)%MOD);

	return 0;
}
