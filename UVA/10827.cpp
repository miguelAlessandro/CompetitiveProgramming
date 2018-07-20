#include <bits/stdc++.h>
using namespace std;

const int N = 80;
long long a[3*N][3*N], acum[3*N][3*N];
long long kad[3*N];
int n, t;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%lld", &a[i][j]);

		for(int i = 1; i <= 2*n; ++i){
			for(int j = 1; j <= 2*n; ++j){
				if(i > n) a[i][j] = a[i-n][j];
				else if(j > n) a[i][j] = a[i][j-n];
				//printf("%lld, ", a[i][j]);
			}

			//puts("");
		}
		for(int i = 1; i <= 2*n; ++i){
			for(int j = 1; j <= 2*n; ++j){
				acum[i][j] = a[i][j] + acum[i-1][j];
				//printf("%lld, ", acum[i][j]);
			}
			//puts("");
		}

		long long maximum = -1000000000, maximum2 = -1000000000;		
		for(int i = 1; i <= 2*n; ++i){
			maximum2 = -1000000000;
			for(int j = i; j <= i+n-1 and j <= 2*n; ++j){
				
				for(int k = 1; k <= 2*n; ++k)
					kad[k] = acum[j][k] - acum[i-1][k];
				
				long long maxi = -1000000000, sol = 0;
				int last = 1;
				for(int k = 1; k <= 2*n; ++k){
					if(k - last + 1 <= n){
						if(kad[k] < sol+kad[k])  
							sol = sol+kad[k];
						else{
							last = k;
							sol = kad[k];
						}
					}	
					else{
						sol -= kad[last++];
						if(kad[k] < sol+kad[k])
							sol += kad[k];
						else{
							last = k;
							sol = kad[k];
						}
					}
					maxi = max(maxi, sol);			
				}
				maximum2 = max(maximum2, maxi);
			}
			maximum = max(maximum, maximum2);
		}

		printf("%lld\n", maximum);

	}	

	return 0;
}
