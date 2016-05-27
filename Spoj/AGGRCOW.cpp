#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000;
int a[N];
int t, n, c;

bool p(int mid){
	int m = 1, k = 0;
	for(int i = 0; i < n; ++i)
		if(a[i] - a[k] >= mid)
			m = m + 1, k = i;
	return m >= c;
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &c);
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);	

		sort(a, a+n);
		int lo = 0, hi = 1000000000;
		while(lo < hi){
			int mid = lo + (hi-lo+1)/2;
			if(p(mid)) lo = mid;
			else hi = mid-1;
		}
		printf("%d\n", lo);
	}

	return 0;
}

