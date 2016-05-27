#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int N = 15, M = 105;
int n, m;
int w[N][M], p[N][M];
const int di[3] = {-1, 0, 1};
long long l[N][M];

int main(){
	
	while(scanf("%d %d", &n, &m) == 2){
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &w[i][j]), l[i][j] = (1LL<<40);

		for(int i = 0; i < n; ++i)
			l[i][m-1] = w[i][m-1];
		
		for(int j = m-2; j >= 0; --j)
			for(int i = 0; i < n; ++i)
				for(int k = 0; k < 3; ++k){
					long long temp = w[i][j] + l[(n+i+di[k])%n][j+1];
					if(l[i][j] > temp){
						l[i][j] = temp;
						p[i][j] = (n+i+di[k])%n;
					}
					else if(l[i][j] == temp)
						p[i][j] = min(p[i][j], (n+i+di[k])%n);
				}
		
		long long mini = LLONG_MAX;
		for(int i = 0; i < n; ++i)
			mini = min(mini, l[i][0]);
		
		int solve;
		for(int i = 0; i < n; ++i) 
			if(l[i][0] == mini){
				solve = i;
				break;
			}
		
		for(int i = 0; i < m; ++i){
			printf("%d%c", solve+1, i == m-1 ? '\n' : ' ');
			solve = p[solve][i];
		}
		printf("%lld\n", mini);
			
	}



	return 0;
}
