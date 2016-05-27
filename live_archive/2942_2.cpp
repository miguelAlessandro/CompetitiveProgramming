#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 3005;

long long X[N], Y[N], Z[N], dp[N];
int in[N], t, n, nc;	
 
bool comp(const int& i, const int& j){
	return X[i] < X[j];
}

int main(){
	
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i) 
			scanf("%*s %lld %lld %lld", X+i, Y+i, Z+i), in[i] = i;
		sort(in, in+n, comp);
		dp[n] = 0;
		for(int i = n-1; i >= 0; --i){
			int lo = i+1, hi = n-1, x = X[in[i]]+Y[in[i]];			
			while(lo < hi){
				int mid = lo + (hi-lo+1)/2;
				if(X[in[mid]] <= x) lo = mid;
				else hi = mid-1; 
			}
			if(X[in[lo]] < x) lo++;
			dp[i] = max(dp[i+1], dp[lo] + Z[in[i]]);
		}
		if(nc++) putchar('\n');
		printf("%lld\n", dp[0]);
	}

	return 0;
}
