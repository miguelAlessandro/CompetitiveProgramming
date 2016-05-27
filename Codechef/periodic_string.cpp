#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

typedef pair<long long, long long> ii;
vector<ii> p;
vector< pair<long long, bool> > ex;

void factor(int n, vector<ii>& p){
	for(int i = 2; i*i <= n; ++i)
		if(n%i == 0){
			ii q(i, 0LL);
			while(n%i == 0){
				q.second++;
				n /= i;
			}
			p.push_back(q);
		}
	if(n > 1LL)
		p.push_back(ii(n, 1LL));
}


long long expfast(long long a, long long n, long long mod){
	long long r = 1LL;
	while(n > 0LL){
		if(n&1LL) r = (r*a)%mod;
		n >>= 1;
		a = (a*a)%mod;
	}
	return r;
}

void backtracking(int in, long long r, bool sign){
	if(in >= (int)(p.size())){
		ex.push_back(make_pair(r, sign));
		return;
	}
	long long e = expfast(p[in].first, p[in].second-1LL, LLONG_MAX);
	backtracking(in+1, r*e, not sign);
	backtracking(in+1, r*e*p[in].first, sign);
}

int main(){
	long long n, m;
	scanf("%lld %lld", &n, &m);
	factor(n, p);
	backtracking(0LL, 1LL, true);
	long long sum = 0LL;
	for(int s, i = 0; i < int(ex.size()); ++i){
		ex[i].second == true ? s = 1 : s = -1;
		sum = (m + sum + s*expfast(2LL, ex[i].first, m))%m;
	}
	printf("%lld\n", sum);

	return 0;
}


