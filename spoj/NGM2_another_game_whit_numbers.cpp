#include <iostream>
#include <cstdio>
using namespace std;

const int N = 17;
int n, m;
int s[N];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	
	scanf("%d %d", &n, &m);	
	
	for(int i = 0; i < m; ++i)
		scanf("%d", s+i);

	int answer = n;	
	for(int mask = 1; mask < (1<<m); ++mask){
			
		int res = 1;
		bool ok = true;
		for(int j = 0; j < m and ok; ++j)
			if(mask&(1<<j)){
				
				if((n + s[j] - 1)/s[j] < res/gcd(res, s[j])) ok = false;
				res = res/gcd(res, s[j])*s[j];			
				
			}

		if(not ok) continue;

		if(__builtin_popcount(mask)&1) answer -= n/res;
		else answer += n/res;
	}

	printf("%d\n", answer);

	return 0;
}
