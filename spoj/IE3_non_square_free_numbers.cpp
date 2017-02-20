#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 160000;
int Mobius[N];
bool notprime[N];
long long n;
int t;

void criba(){

	for(int i = 4; i < N; i += 2) notprime[i] = true;
	
	for(int i = 3; i*i < N; i += 2)
		if(not notprime[i])
			for(int j = i*i; j < N; j += 2*i)
				notprime[j] = true;
}

void mobius(){

	memset(Mobius, -1, sizeof Mobius);

	for(long long i = 2; i < N; ++i)
		if(not notprime[i])
			for(long long j = i; j < N; j += i)
				if(j%(i*i) == 0) Mobius[j] = 0;
				else Mobius[j] *= -1;
}

long long predicate(long long x){

	long long answer = 0;
	for(long long i = 2; i*i <= x; ++i)
		answer += Mobius[i]*(x/(i*i));

	return answer;
}

int main(){

	criba();
	mobius();	
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		
		long long lo = 2, hi = 26000000000LL; 
		while(lo < hi){
			long long mid = lo + (hi-lo)/2;
			if(predicate(mid) < n) lo = mid+1;
			else hi = mid;
		}
		
		printf("%lld\n", lo);
	}

	return 0;
}
