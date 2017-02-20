#include <bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> v;

int main(){
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]);

		sort(v.begin(), v.end());
		long long sum = v.back();
		for(int l = 2, i = 0; i+1 < v.size(); ++i, ++l)
			sum += l*1LL*v[i];

		printf("%lld\n", sum);
	}

	return 0;
}
