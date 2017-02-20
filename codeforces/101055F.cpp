#include <bits/stdc++.h>
using namespace std;

int n, q;
char c;

int main(){
	
	scanf("%d", &q);
	
	for(int i = 0; i < q; ++i){
		scanf("%d", &n);
		int l = 0;
		while(getchar() != '\n') l++;
		
		long long ans = 1;
		while(n > 0){
			ans *= n;
			n -= l;
		}
		printf("%I64d\n", ans);
	}

	return 0;
}
