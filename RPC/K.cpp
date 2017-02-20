#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int t, n;
long double ac[N][N];
long double a[N][N], P[N], Q[N], E;

int backtracking(int pos, int )

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%Lf", P+i);
		for(int i = 0; i < n; ++i)
			scanf("%Lf", Q+i);

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				scanf("%Lf", &a[i][j]);
				ac[i][j] = a[i][j];
				if(j) ac[i][j] += a[i][j];			
			}

				

	}

	return 0;
}
