#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;
const long long MOD = 1000000007;
const long long two = (MOD+1)/2;
long long a, b, n;
long long p[40];

long long sum(long long a){
	a %= MOD;
	return a*(a+1)%MOD*two%MOD;
}

long long f(long long a, long long y){

	return (sum(a/y)%MOD)*(y%MOD)%MOD;
}


int primes(long long n){
	
	int t = 0;
	for(long long i = 2; i*i <= n; ++i)
		if(n%i == 0){
			while(n%i == 0)
				n /= i;

			p[t++] = i;
		}

	if(n > 1) p[t++] = n;

	long long res = 0;
	long long y = 1;
	for(int i = 1; i < (1<<t); ++i, y = 1)
		if(__builtin_popcount(i)&1){
				
			for(int j = 0; j < t; ++j) 
				if(i&(1<<j)) y = y*p[j];	
			
			res = ((res + (f(b, y) - f(a, y)))%MOD + MOD)%MOD;
		}
		else{
			
			for(int j = 0; j < t; ++j)
				if(i&(1<<j)) y = y*p[j];


			res = ((res - (f(b, y) - f(a, y)))%MOD + MOD)%MOD;
		} 

	return res;
}


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %lld", &n, &a, &b);
		a--;
		long long r = primes(n);		
		long long z = ((sum(b) - sum(a))%MOD + MOD)%MOD;
		printf("%lld\n", ((z-r)%MOD + MOD)%MOD);
	}

	return 0;
}
