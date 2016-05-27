#include <bits/stdc++.h>

using namespace::std;

int t, n, m, nc=1;
long long sum, f, l, x;

long long mcd(long long a, long long b){
	return b ? mcd(b, a%b) : abs(a);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n); l = sum = 0;;
        for(int i = 0; i < n; ++i){
            scanf("%d", &m);  
			for(int j = 0; j < m; ++j){
				scanf("%lld", &x);
				if(j==0)
					 sum += x, f = x;
				else
					l = mcd(l, x-f);
			}
		} 
        printf("Case #%d: %lld\n", nc++, mcd(l, sum));
    }

    return 0;
}
