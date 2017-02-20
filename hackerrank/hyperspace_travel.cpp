#include <bits/stdc++.h>
using namespace std;


const int N = 10005;
const int M = 105;
int n, m;
int a[M][N];


int main(){

	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[j][i]);

	for(int j = 0; j < m; ++j){
		sort(a[j], a[j]+n);	

		printf("%d%c", a[j][(n-1)/2], (j==m-1) ? '\n':' ');
	}


	return 0;
}
