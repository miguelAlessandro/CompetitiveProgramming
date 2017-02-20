#include <iostream>
#include <cstdio>
using namespace std;

const int N = 12;
const int MOD = 2004;
int n, a, b;
int nf[N], m[N];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int C(int x){

	int den = nf[n];
	int num = 1;

	for(int i = 0; i < n; ++i){
		int nx = x - i;
		int g = gcd(nx, den);
		nx /= g;
		den /= g;
		nx %= MOD;
		num = (num*nx)%MOD;
	}	

	return num;
}

int predicate(int x){
	
	int ans = C(n+x);

	for(int mask = 1; mask < (1<<n); ++mask){
		
		int nx = x;
		for(int j = 0; j < n; ++j)
			if(mask&(1<<j))
				nx -= m[j] + 1;

		int comb;
		if(nx < 0) comb = 0;
		else comb = C(n+nx);		

		if(__builtin_popcount(mask)&1) ans = (MOD + ans - comb)%MOD;
		else ans = (ans + comb)%MOD;
	}

	return ans;
}


int main(){
	
	nf[0] = 1;
	for(int i = 1; i <= 10; ++i)
		nf[i] = i*nf[i-1];

	scanf("%d %d %d", &n, &a, &b);
	
	for(int i = 0; i < n; ++i)
		scanf("%d", m+i);
	
	printf("%d\n", ((predicate(b) - predicate(a-1))%MOD + MOD)%MOD);

	return 0;
}
