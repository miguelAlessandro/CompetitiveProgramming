#include <bits/stdc++.h>
using namespace std;

const int N = 100005;	
int L[N], R[N];
int n;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d %d", L+i, R+i);

	int l = 0, r = 0;
	for(int i = 0; i < n; ++i){
		l += L[i];
		r += R[i];
	}

	int temp = abs(l-r);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		if(abs(l - 2*L[i] - r + 2*R[i]) > temp){
			temp = abs(l - 2*L[i] - r + 2*R[i]);
			ans = i+1;
		}
	

	printf("%d\n", ans);

	return 0;
}
