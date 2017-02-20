#include <bits/stdc++.h>
using namespace std;

int t;
long long l, r;
int d[4] = {1, 0, 1, 0};
int p[4] = {1, 0, 0, 1};

int main(){

	scanf("%d", &t);

	while(t--){
		scanf("%lld %lld", &l, &r);
		if(r - l + 1 >= 4) puts("0");
		else{
			int ans = d[l%4]*l + p[l%4];
	
			for(int i = l+1; i <= r; ++i)
				ans &= d[i%4]*i + p[i%4];
		
			printf("%d\n", ans);
		}
	}

	return 0;
}
