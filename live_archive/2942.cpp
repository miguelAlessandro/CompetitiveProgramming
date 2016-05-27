#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int n;
struct point{
	long long x, y, z;
	point(){x=y=z=0;}	
	point(long long xx, long long yy, long long zz) : x(xx), y(yy), z(zz) {}
	bool operator<(const point& q){
		return x < q.x or x == q.x and y < q.y;
	}
} p[N];

long long dp[N], x, y, z;

int main(){
	
	int nc = 0;
	while(scanf("%d", &n) == 1){
		for(int i = 1; i <= n; ++i)
			scanf("%*s %lld %lld %lld%*c", &x, &y, &z), p[i] = point(x, y, z);
	
		sort(p+1, p+n+1);
		memset(dp, 0, sizeof dp);
	
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < i; ++j)
				if(p[j].x + p[j].y <= p[i].x and dp[i] < dp[j]+p[i].z)
					 dp[i] = dp[j] + p[i].z;

		if(nc++) puts("");
		long long maxi = 0;
		for(int i = 1; i <= n; ++i) maxi = max(maxi, dp[i]);
		printf("%lld\n", maxi);
	}

	return 0;
}


