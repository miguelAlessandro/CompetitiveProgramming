#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 55

using namespace::std;

int t, n, m;
vector<int> v[N];
long long r, sum1;

long long gcd(long long a, long long b){return (b == 0) ? a : gcd(b, a%b);}

int main(){
    
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        scanf("%d", &n); r = 0ll; sum1 = 0ll;
        for(int j = 0; j < n; ++j){
            scanf("%d", &m); v[j].resize(m);
            for(int k = 0; k < m; ++k)
                scanf("%d", &v[j][k]);
            sort(&v[j][0], &v[j][0] + m);
            for(int k = 1; k < m; ++k)
                if(r + v[j][k-1] > v[j][k])
                    r = gcd(r, v[j][k] - v[j][k-1]);
                else
                    r = gcd(v[j][k] - v[j][k-1], r);
            sum1 += v[j][0];
        }
        if(r < sum1) swap(r, sum1);
        printf("Case #%d: %lld\n", i, gcd(r, sum1));
    }
    return 0;
}
