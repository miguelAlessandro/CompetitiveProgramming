#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
vector< pair< int, pair<bool, int> > > v;
int w[N], n;
priority_queue<long long> Q;
long long dp[N];

int main(){

	scanf("%d", &n);
	for(int x, y, z, i = 1; i <= n; ++i){
		scanf("%d %d %d", &x, &y, &z);
		v.push_back({x, {true, i}});
		v.push_back({x+z, {false, i}});
		w[i] = y;
	}
	
	sort(v.begin(), v.end());

	Q.push(0);
	for(auto s : v)
		if(s.second.first) dp[s.second.second] = Q.top() + w[s.second.second]; 
		else Q.push(dp[s.second.second]);
	
	printf("%lld\n", Q.top());	

	return 0;
}
