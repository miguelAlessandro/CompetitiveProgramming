#include <bits/stdc++.h>

using namespace::std;

int t, n, m, x, ant;
int minimom;
vector<int> V[55];
long long sum;

long long mcd(long long a, long long b){return b == 0 ? a : mcd(b, a%b);}

int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++k){
        scanf("%d", &n);
		sum = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &m); V[i].resize(m);
			for(int j = 0; j < m; ++j){
				scanf("%d", x);
            	if(i+j==0) ant = x;
				else ant = abs(mcd(ant, x));
				if(i==0) sum += x;
			}
		}
    
        printf("Case #%d: %lld\n", k, mcd(ant, sum));
    }

    return 0;
}
