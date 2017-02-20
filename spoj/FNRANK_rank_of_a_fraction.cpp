#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;
int prime[N];
int fp[10];
int n, a, b, t;

void criba(){
	
	for(int i = 4; i < N; i += 2) prime[i] = 2;
	for(int i = 3; i*i < N; i += 2)
		if(not prime[i])
			for(int j = i*i; j < N; j += 2*i)
				prime[j] = i;
}

int fact(int x){

	int T = 0;
	while(prime[x]){
		int f = prime[x];		
		while(x%f == 0) x /= f;
		fp[T++] = f;
	}
	if(x > 1) fp[T++] = x;

	return T;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){

	criba();
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &a, &b);
		
		if(a > b) a = b = 1;		
		else{
			int g = gcd(a, b);
			a /= g;
			b /= g;	
		}	

		int answer = 1;
		for(int i = 1; i <= n; ++i){
			int nn = 1ll*a*i/b;// - (i%b == 0);
			int local_answer = nn;			
			int len = fact(i);			
			for(int mask = 1; mask < (1<<len); ++mask){

				int prod = 1;
				for(int j = 0; j < len; ++j)
					if(mask&(1<<j))	
						prod *= fp[j];
		
				if(__builtin_popcount(mask)&1) local_answer -= nn/prod;
				else local_answer += nn/prod;
			}
			
			answer += local_answer;
		}

		printf("%d\n", answer);
	}
	
	return 0;
}
