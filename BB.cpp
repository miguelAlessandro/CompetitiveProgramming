#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, t, nc=1;
int w[N];

int main(){

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", w+i);

		sort(w, w+n);

		int r = 0;
		int lo = 49/w[n-1], hi = n-1;
		while(lo <= hi){					

			r += 1;
			
			
			hi -= 1;
			if(hi == -1) break;
			lo += 49/w[hi];
		}

		printf("Case #%d: %d\n", nc++, r);
	}

	return 0;
}
