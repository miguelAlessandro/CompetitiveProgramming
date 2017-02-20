#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int A[N], B[N];
int n, g, m, x;


int main(){
	
	scanf("%d", &g);
	while(g--){
		scanf("%d %d %d", &n, &m, &x);
		for(int i = 0; i < n; ++i) scanf("%d", A+i);
		for(int i = 0; i < m; ++i) scanf("%d", B+i);

		long long a = 0, b = 0;
		int lb=0;	

		for(int i = 0; i < m; ++i)
			if(b + B[i] <= x){
				b += B[i];
				lb++;
			}
			else break;

		int ans = lb;
		for(int la = 0; la < n; ++la)
			if(a + A[la] <= x){
				a += A[la];
				while(b + a > x){
					b -= B[lb-1];
					lb--;
				}

				ans = max(ans, la+lb+1);
			}
			else break;
		
		printf("%d\n", ans);
	}

	return 0;
}
