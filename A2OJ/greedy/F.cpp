#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 1000007;
int t, n, m, nc=1;
long long p, q, r, x, y, z; 
long long a[N], s[N];
bool u[N];

int main(){

	scanf("%d", &t);
	while(t--){

		memset(u, false, sizeof u);

		scanf("%d %d", &n, &m);
		scanf("%lld %lld %lld %lld %lld %lld", &p, &q, &r, &x, &y, &z);
		
		for(int i = 1; i <= n; ++i)
			a[i] = (p*i*i + q*i + r)%MOD;

		for(int i = 1; i <= m; ++i){
			s[i] = (x*i*i + y*i + z)%n + 1;
			u[s[i]] = true;
		}

		long long mini = INT_MAX;
		int id;		

		for(int i = 1; i <= n; ++i)
			if(not u[i] and a[i] < mini){
				mini = a[i];	
				id = i;
			}

		long long ans = 0;
		for(int i = 1; i <= n; ++i)
			if(i != id)
				ans += a[i]*mini;

		printf("Case %d: %lld\n", nc++, ans);
	}

	return 0;
}
