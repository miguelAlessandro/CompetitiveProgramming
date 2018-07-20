#include <iostream>
#include <cstdio>
#include <complex>

#define f(x, y, z) for(int x = y; x < z; ++x)
#define N 1005

using namespace::std;

typedef complex<double> point;

point P[30];
int t, n, target;
double dist[30][30], memo[1<<16];


double matching(int bitmask){

    if(memo[bitmask] > -0.5) return memo[bitmask];
    
    if(bitmask == target) return  memo[bitmask] = 0;

    double ans = 2000000000.0;

    int p1 = 0;
    for(; p1 < 2*n; ++p1)
        if(!(bitmask & (1 << p1)))
            break;

    for(int p2 = p1 + 1; p2 < 2*n; ++p2)
        if(!(bitmask & (1 << p2)))
            ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));

    return memo[bitmask] = ans;    
}


int main(){

    int t = 1, x, y;
    while(scanf("%d", &n), n){

        for(int i = 0; i < 2*n; ++i)
            scanf("%*s %d %d", &x, &y), P[i].real(x), P[i].imag(y);
        for(int i = 0; i < 2*n - 1; ++i)
            for(int j = i+1; j < 2*n; ++j)
                dist[i][j] = dist[j][i] = abs((P[i] - P[j]));
        
        for(int i = 0; i < (1<<16); ++i) memo[i] = -1.0;
        target = ((1 << (2*n)) - 1);
        printf("Case %d: %.2lf\n", t++, matching(0));
    }

    return 0;
}
