#include <iostream>
#include <cstdio>
using namespace std;


const int N = 105;
int a[N], L[N], R[N];
int C[N];
int n, m;

int main(){

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	
	for(int i = 0; i < m; ++i)
		scanf("%d %d", L+i, R+i);



	for(int i = 0; i < m; ++i)
		for(int j = L[i]; j <= R[i]; ++j)
			C[i] += a[j];	

	int ans = 0;
	for(int i = 0; i < m; ++i) 
		if(C[i] > 0)
			ans += C[i];
	
	printf("%d\n", ans);


	return 0;
}
