#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n;
long long s, x;
long long c[N], d[N];

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%lld %d %lld", &s, &n, &x);
		for(int i = 1; i <= n; ++i)
			scanf("%lld", c+i);

		d[0] = s;
		int l = -1;
		long long acum = 0;
		for(int i = 0; i <= n; ++i){
			if(x < d[i]) break;
			l++;
			if(i < n){
				if(x - d[i] - c[i+1] < acum) break;
				d[i+1] = acum + d[i] + c[i+1]; 
			}
			acum += d[i];
		}
		

		for(int i = l; i >= 0; --i)
			if(x >= d[i]) x -= d[i];	

		puts(x ? "no" : "yes");
	}

	return 0;
}
