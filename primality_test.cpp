#include <iostream>
#include <cstdio>
using namespace std;

long long expmod(long long a, long long n, long long m){
	long long r = 1;
	while(n>0){
		if(n&1) r = r*a%m;
		a = a*a%m;
		n >>= 1;
	}
	return r;
}

bool primality_test(long long n, int a){
	if(n%2 == 0) return n==2;
	if(n==a) return true;
	long long m=n-1, s=0;
	while(m%2 == 0){
		m >>= 1;
		s += 1;
	}
	
	long long x = expmod(a, m, n);
	if(x==1 or x == n-1) return true;
	for(int i = 1; i<s; ++i){
		x = (n+x*x)%n;
		if(x == n-1) return true;
	}
	return false;
}
long long n;

int main(){

	int v[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	scanf("%lld", &n);
	
	for(int i = 2; i < 999999; ++i){
		long long j = n-i-3; bool prime = true;
		for(int k = 0; k < 12; ++k) prime &= (primality_test(i, v[k]) and primality_test(j, v[k]));
		if(prime){
			printf("3 %lld %lld\n", i, j);
			return 0;
		}
	}

	return 0;
}
