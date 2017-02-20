#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n;
int a[N], b[N];
int c[N], d[N];

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", a+i, b+i);

	/*	
	c[0] = a[0];
	d[0] = b[0];
	int k = 0;
	for(int i = 1; i < n; ++i)
		if(b[i] == d[k]){
			c[k] += a[i];
		}
		else{
			d[++k] = b[i];
			c[k] = a[i];
		}		


	k++;*/


		int x = INT_MAX, y = INT_MIN, z = INT_MIN;
		int hi = 0;

		for(int i = 0; i < n; ++i){

			if(b[i] == 1) x = min(x, hi), z  = max(x, hi); 
			else y = max(y, hi);

			hi += a[i];
		}

		if(y < x){
			if(y != INT_MIN) printf("%d\n", hi + 1899 - y);
			else puts("Infinity");
		}
		else puts("Impossible");
		


	return 0;
}
