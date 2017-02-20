#include <bits/stdc++.h>
using namespace std;

const int N = 48;
long long n;
int q;
bool p[N];
vector<long long> pv;



int main(){

	
	for(int i = 4; i < N; i += 2)
		p[i] = true;

	for(int i = 3; i*i < N; i += 2)
		if(not p[i])
			for(int j = i*i; j < N; j += 2*i)
				p[j] = true;

	for(int i = 2; i < N; ++i)
		if(not p[i])
			pv.push_back(i);

	for(int i = 1; i < pv.size(); ++i)
		pv[i] *= pv[i-1];


	scanf("%d", &q);
	while(q--){
		scanf("%lld", &n);
		int r = 0;
		for(int i = 0; i < pv.size(); ++i)
			if(pv[i] <= n)
				r++;
			else break;

		printf("%d\n", r);
	}

	return 0;
}
