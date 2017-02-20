#include <bits/stdc++.h>
using namespace std;

long long primes(long long n){

	
	int t = 0;
	long long f[20];
	int c[20];

	memset(c, 0, sizeof c);	

	for(long long i = 2; i*i <= n; ++i)
		if(n%i == 0){
			f[t] = i;
			while(n%i == 0){
				c[t] += 1;
				n /= i;
			}		
			t++;
		}

	if(n > 1){
		f[t] = n;
		c[t] = 1;
		t++;
	}	
	
	long long ans = 1;
	for(int i = 0; i < t; ++i){
		long long q = 1, len = 2*c[i] + 1; 
		long long r = 0;
		for(int j = 0; j <= c[i]; ++j){
					
			r += q*len;
			q *= f[i];
			len -= 2;
		}
		ans *= r;
	}

	
	return ans;
}

int t, nc=1;
long long n;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("Case %d: %lld\n", nc++, primes(n));
	}

	return 0;
}
