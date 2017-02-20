#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const long long M = 1000000000000;
int t, n;
bool np[N];
set<long long> s;
vector<long long> p;
vector<int> v;

void criba(){
	np[1] = true;
	for(int i = 4; i < N; i += 2) np[i] = true;
	for(int i = 3; i*i < N; i += 2)
		if(not np[i])
			for(int j = i*i; j < N; j += 2*i)
				np[j] = true;

	long long po = 2;
	int l = 1;
	while(po <= M){
		if(not np[l+1] and l != 1) s.insert(po);
		po <<= 1;
		l += 1;
	}	

	for(int i = 3; i < N; i += 2)
		if(not np[i]){
			po = i;
			l = 1;
			while(po <= M){
				if(not np[l+1] and l != 1) s.insert(po);
				if(po > (M+i-1)/i) break;				
				po *= i;
				l += 1;
			}
		}
}

int main(){

	criba();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		p.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &p[i]);

		sort(p.rbegin(), p.rend());

		v.clear();
		for(int i = 0; i < n; ++i)
			if(s.find(p[i]) != s.end()) v.push_back(i+1);
		
		if(int(v.size()) == 0) puts("No supporter found.");
		for(int i = 0; i < v.size(); ++i)
			printf("%d%c", v[i], (i+1==v.size()) ? '\n' : ' ');

	}	

	return 0;
}
