#include <iostream>
#include <cstdio>
using namespace std;

const int N = 300005, M = 1000000009;
int ft[2][N], fib[N];
int n, q, x, y, z;

void update(int x, int open, int add){
	while(x <= n){
		ft[0][x] += open; 
		ft[1][x] = (ft[1][x]+add)%M;
		x += x&(-x);
	}
}

int query(int x){
	int open = 0, add = 0, ran = x;
	while(x > 0){
		open += ft[0][x];
		add = (add+ft[1][x])%M;			
		x -= x&(-x);
	}
	return (M + ((long long)open)*fib[ran+2] + add)%M; 
}

int main(){

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x); 
		update(i, 0, x);	
	}
	
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= n+2; ++i)
		fib[i] = (fib[i-1]+fib[i-2])%M;

	while(q--){
		scanf("%d %d %d", &x, &y, &z);
		if(x == 1){
			update(y, 1, -1);
			update(z, -1, fib[z-y+3]);
		}		
		else
			printf("%d\n", (M + query(z)-query(y-1))%M);
		for(int i = 1; i <= n; ++i)
			printf("%d, ", query(i)-query(i-1));
		puts("");	
	}

	return 0;
}
