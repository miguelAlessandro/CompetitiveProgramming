#include <bits/stdc++.h>
using namespace std;

const int N = 500, M = 22;
long double dp[N][M];
int h, s, t, nc = 1;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &h, &s);		

		long double num = 0, den = 1;		

		for(int x, y, z, c, i = 0; i < s; ++i){
			scanf("%d%*c%d", &x, &y);
			
			c = getchar();
			if(c == '+') scanf("%d", &z);		
			else if(c == '-'){
				scanf("%d", &z);
				z *= -1;	
			}
			else z = 0;

			if(h - z > x*y) continue;
			else{
			
				long double r = 0;
				long double p = 1;
				
				for(int j = 0; j <= x; ++j)
					for(int k = 0; k <= 400; ++k)
						dp[k][j] = 0; 


				dp[0][0] = 1;
				for(int j = 1; j <= x; ++j)
					for(int k = 400; k >= 1; --k)
						for(int l = 1; k >= l and l <= y; ++l)
							dp[k][j] += dp[k-l][j-1];


				for(int j = 1; j <= 400; ++j) if(h - z <= j) r += dp[j][x];
				for(int j = 1; j <= x; ++j) p *= y;
				
			
				if(num*p < r*den) num = r, den = p;
			}				

		}
		printf("Case #%d: %Lf\n", nc++, (long double)(num)/den);

	}

	return 0;
}
