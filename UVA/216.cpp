#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 10;
int n, target;
int X[N], Y[N], p[260][N];
double dis[N][N],
	   dp[260][N];

double matching(int bitmask, int front){
	if(dp[bitmask][front] > -0.5) return dp[bitmask][front];
	if(bitmask == target) return dp[bitmask][front] = 0.0;
	double ans = 10000000.0;

	for(int i = 0; i < n; ++i)
		if(!(bitmask & (1<<i))){
			double temp = dis[front][i] + matching(bitmask | (1<<i), i);
			if(ans > temp){
				ans = temp;
				p[bitmask][front] = i;
			}
		}

	return dp[bitmask][front] = ans;
}

int main(){

	int nc = 1;
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i)
			scanf("%d %d", X+i, Y+i);
		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dis[i][j] = 16.0 + hypot(double(X[i]-X[j]), double(Y[i]-Y[j]));

		for(int i = 0; i < (1<<n); ++i)
			for(int j = 0; j < n; ++j) dp[i][j] = -1.0;
		
		int in;
		target = (1<<n)-1;
		double mini = 10000000.0;
		for(int i = 0; i < n; ++i){
			double temp = matching((1<<i), i);
			if(mini > temp){
				mini = temp;
				in = i;
			}
		}
		int mask = (1<<in);
		puts("**********************************************************");
		printf("Network #%d\n", nc++);
		for(int j = in, k = p[mask][j], i = 1; i < n; ++i){
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", X[j], Y[j], X[k], Y[k], dis[j][k]);
			j = k; mask |= (1<<k); k = p[mask][j];
		}
		printf("Number of feet of cable required is %.2lf.\n", mini);
	}

	return 0;
}
