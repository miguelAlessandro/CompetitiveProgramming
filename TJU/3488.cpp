#include <bits/stdc++.h>
using namespace std;

int t, n;
priority_queue<int, vector<int>, greater<int> > Q;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int x, i = 1; i <= n; ++i){
			scanf("%d", &x);
			Q.push(x);
		}

		long long r = 0;
	
		while(Q.size() >= 2){
			int a = Q.top(); Q.pop();
			int b = Q.top(); Q.pop();
			r += a+b;			
			Q.push(a+b);
		}
		while(not Q.empty()) Q.pop();

		printf("%lld\n", r);
	}

	return 0;
}
