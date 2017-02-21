#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	long long sum;
	int nc =1;
	while(scanf("%d", &n), n){
		sum = 0;
		for(int i = 1; 3*i <= n-3; ++i)
			sum += (n-3*i-1)/2;
	
		printf("Case %d: %lld\n", nc++, sum);
	}

	return 0;
}

