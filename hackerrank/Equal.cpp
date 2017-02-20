#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n, t;
int a[N];

int f(int x){

	int ans = 0;
	for(int i = 0; i < n; ++i){
		int y = a[i] - x;
		ans += y/5; y %= 5;
		ans += y/2; y %= 2;
		ans += y;
	}

	return ans;
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);

		int lim = INT_MAX;
		for(int i = 0; i < n; ++i) lim = min(lim, a[i]);

		
		int r = INT_MAX;
		for(int i = 0; i <= 20; ++i)
			r = min(r, f(lim-i));

		printf("%d\n", r);
	}

	return 0;
}
