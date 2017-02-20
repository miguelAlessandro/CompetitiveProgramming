#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 105;
int A[N];
int n, x;

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", A+i);

	scanf("%d", &x);
	int ways = 0;
	int tw = n*(n-1)/2;


	sort(A, A+n);
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			if(A[i] > x or A[j] - A[i] > x or 100 - A[j] > x) ways += 1;
	
	printf("%lf\n", double(ways)/tw);

	return 0;
}
