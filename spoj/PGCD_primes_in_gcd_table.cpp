#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
int t, a, b;
int Prime[N];
int Mobius[N];
int Factor[N];

void criba(){

	for(int i = 4; i < N; i += 2)  Prime[i] = 2;
	for(int i = 3; i*i < N; i += 2)
		if(not Prime[i])
			for(int j = i*i; j < N; j += 2*i)
				Prime[j] = i;			
		
}

void mobius(){
	memset(Mobius, -1, sizeof Mobius);
	for(long long i = 2; i < N; ++i)
		if(not Prime[i])
			for(int j = i; j < N; j += i)
				if(j%(i*i) == 0) Mobius[j] = 0;
				else Mobius[j] *= -1;
}

void fact(){

	Factor[1] = 0;
	for(int i = 2; i < N; ++i)
		if(not Prime[i]) Factor[i] = 1;
		else Factor[i] = 1 + Factor[i/Prime[i]];
}

int main(){

	criba();
	mobius();	
	fact();
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);

		long long answer = 0;
		int x = min(a, b);
		for(long long i = 2; i <= x; ++i)
			answer += 1ll*Factor[i]*Mobius[i]*((a/i)*(b/i) - (a/(i*i))*(b/(i*i)));

		printf("%lld\n", answer);
	}

	return 0;
}
