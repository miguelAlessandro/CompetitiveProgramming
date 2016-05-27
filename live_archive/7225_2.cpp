#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace::std;

const int N = 50;
int t, n, m;
int v[N][N];
int r, sum1;

int gcd(int a, int b){return (b == 0) ? a : gcd(b, a%b);}

int main(){
    
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        
		scanf("%d", &n); r = 0; sum1 = 0ll;
        for(int j = 0; j < n; ++j){
            scanf("%d", &m);
            for(int k = 0; k < m; ++k)
                scanf("%d", &v[j][k]);
            sort(v[j], v[j] + m);
            for(int k = 1; k < m; ++k)
                    r = gcd(r, v[j][k] - v[j][k-1]);
            sum1 += v[j][0];
        }
        printf("Case #%d: %d\n", i, gcd(r, sum1));
    }
    return 0;
}
