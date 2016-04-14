#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define fd(x, y, z) for(int x = y; x >= z; x--)
#define FOR(A, X) for(typeof A.begin() X = A.begin(); X != A.end(); X++)
#define N 30010

using namespace::std;

map<unsigned int, unsigned int> G[N];
unsigned int n, m;
unsigned long long c[N], d[N];

int main( void ){

    scanf("%u %u", &n, &m);   
    f(i, 0, m)
    {
        int a, b;
        scanf("%u %u", &a, &b);
        a--, b--;
        G[a][b]++;
    }

    d[n-1] = 1;
    fd(i, n-1, 0)
    {
        FOR(G[i], it)
            d[i] += it->second * d[it->first], 
            c[i] = max(c[i], c[it->first]);
        
        c[i] += d[i];
    }

    printf("%lld\n", c[0]);

    return 0;
}
