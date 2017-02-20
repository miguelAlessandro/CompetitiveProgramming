#include <bits/stdc++.h>
using namespace std;

//los numeros 341, 561, 645 son numeros que cumplen el 
//peque;o test de fermat y no son primos.

//si d divide a n, entonces 2^d - 1 divide a 2^n - 1. 
//si n es pseudoprime entonces n divide a 2^n-2 porque
// 2^(n-1) == 1%n entonces 2^n == 2%n por lo cual
//2^n-2 == 0%n, entonces 2^(2^n-2)-1 == mod(2^n-1)
//lo cual genera un numero infinito de pseudoprimos.
 
const int N = 10000005;
bool np[N];

void criba(){
	for(int i = 4; i < N; i += 2) np[i] = true;
	for(int i = 3; i*i < N; i += 2) 
		if(not np[i])
			for(int j = i*i; j <  N; j += 2*i)
				np[j] = true;
}


long long expmod(long long a, long long n, long long m){
	long long r = 1;
	while(n > 0){
		if(n&1) r = (r*a)%m;
		a = (a*a)%m;
		n >>= 1;
	}
	return r;
}

int main(){

	criba();
	for(int i = 2; i < N; ++i){
		bool r = true;
		//for(int j = 2; j <= 100; ++j) if(not np[j]) r &= (expmod(j,i-1,i) == 1);
		if(expmod(2, i-1, i) == 1 and expmod(2, i, i) != 2 and np[i])
			printf("%d\n", i);	
	}

	return 0;
}
