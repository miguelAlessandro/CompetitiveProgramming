#include <bits/stdc++.h>
using namespace std;

const int N = 10003;
int t, n, nc = 1;
int p[N];

int main(){

	scanf("%d", &t);
	while(t--){

		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", p + i);

		int k = 0, r = 0;
		for(int i = 0; i < n; ++i)
			if(p[i] != i+1-k){
				r += 1;
				k++;
			}

		printf("Case %d: %d\n", nc++, r);

	}

	return 0;
}
