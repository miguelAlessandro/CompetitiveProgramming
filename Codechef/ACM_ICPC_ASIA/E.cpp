#include <bits/stdc++.h>
using namespace std;

const int N = 503;
int t, n, l, r;
int v[N];

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			v[i] = i;


		printf("%d\n", n/2);
		l = n/2; r = n/2 + 1;
		while(r - l + 1 <= n){
			for(int i = 1; i <= n; ++i)
				printf("%d%c", v[i], i == n ? '\n' : ' ');		
 			swap(v[l], v[r]);

			l--; r++;
		}
	}	

	return 0;
}
