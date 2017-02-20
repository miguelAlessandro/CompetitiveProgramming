#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10000005;
bool notprime[N];
int Mobius[N];
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

int main(){

	criba();
	mobius();
		
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		
		long long answer = n;
		for(long long i = 2; i*i <= n; ++i)
			answer -= Mobius[i]*(n/(i*i));
		
		printf("%lld\n", answer);
	}

	return 0;
}
