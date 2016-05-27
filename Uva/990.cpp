#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 35;
int t, w, n,
	X[N], Y[N], dp[N][1010];
bool info[N][1010];

void path(int n, int t, int cnt)
{
    if ( n==0 ) printf("%d\n",cnt);
    else if ( info[n][t] ){
        path( n-1, t-3*w*X[n], cnt+1 );
        printf("%d %d\n",X[n],Y[n]);
    }
    else path( n-1, t, cnt );
}


int main(){

	int nc = 0;
	while(scanf("%d %d %d", &t, &w, &n) == 3){
		for(int i = 1; i <= n; ++i) 
			scanf("%d %d", X+i, Y+i);
		
		memset(info, false, sizeof info);
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= t; ++j){
				dp[i][j] = dp[i-1][j];
				if(3*w*X[i] <= j and dp[i][j] < dp[i-1][j-3*w*X[i]] + Y[i]){
					dp[i][j] = dp[i-1][j-3*w*X[i]] + Y[i];
					info[i][j] = true;
				}
			}	
	

		if(nc++) puts("");
		printf("%d\n", dp[n][t]);
		path(n, t, 0);
	}

	return 0;
}
