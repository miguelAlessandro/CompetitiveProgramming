#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 55;

int ft[M][N];
int n, k;
		
void init(){
	memset(ft, 0, sizeof ft);
}
		
void update(int y, int x, const int v){
	while(x < N){
		ft[y][x] = (ft[y][x] + v)%5000000;
		x += x&(-x);
	}
}
			
int query(int y, int x){
	int sum = 0;
	while(x > 0){
		sum = (sum + ft[y][x])%5000000;
		x -= x&(-x);		
	}
	return sum;
}		


int main(){

	scanf("%d %d", &n, &k); 
	init();

	for(int x, i = 1; i <= n; ++i){
		scanf("%d", &x);
		update(1, x+1, 1);	
		for(int j = 2; j <= k; ++j){
			update(j, x+1, query(j-1, x));
		}
	}
	
	printf("%d\n", query(k, N-1));
			
	return 0;
}
