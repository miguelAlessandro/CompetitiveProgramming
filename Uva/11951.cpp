#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int N = 105;
int t, n, m;
long long p[N][N], K;

inline long long costo(int i, int j, int k, int l){
	return p[k][l] - p[i-1][l] - p[k][j-1] + p[i-1][j-1];
}


int main(){

	int nc = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %lld", &n, &m, &K);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				scanf("%lld", &p[i][j]);
				p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
			}	
		
		int area = 0;
		long long cost_min = 0;
		for(int i = 1; i <= n; ++i){
			if((n-i+1)*m < area) break;
			for(int j = 1; j <= m; ++j){
				if((n-i+1)*(m-j+1) < area) break;
				for(int k = i; k <= n; ++k){
					if((k-i+1)*(m-j+1) < area) continue;
					for(int l = j; l <= m; ++l){
						if((k-i+1)*(l-j+1) < area) continue;
						long long cos = costo(i, j, k, l);
						if(cos > K) break;
						if(area < (k-i+1)*(l-j+1)) cost_min = cos;
						area = (k-i+1)*(l-j+1); 
						cost_min = min(cost_min, cos);
					}
				}
			}
		}

		printf("Case #%d: %d %lld\n", nc++, area, cost_min);
	}

	return 0;
}
