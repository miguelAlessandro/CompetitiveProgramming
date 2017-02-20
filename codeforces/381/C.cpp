#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int N = 100005;
int n, m;
int L[N], R[N];
pair<int, int> C[N];
int A[N];

int main(){

	scanf("%d %d", &n, &m);
	int len = INT_MAX;
	for(int i = 0; i < m; ++i){
		scanf("%d %d", L+i, R+i);
		len = min(len, R[i] - L[i] + 1);
	}

	printf("%d\n", len);
	for(int i = 0; i < n; ++i)
		printf("%d ", i%len);
	puts("");


	return 0;
}
