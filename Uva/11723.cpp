#include <iostream>
#include <cstdio>
using namespace std;

int n, m;

int main(){

    int nc = 1;
    while(scanf("%d %d", &n, &m), n+m)
        (n - m) <= 26*m ?
            printf("Case %d: %d\n", nc++, (n - 1)/m):
            printf("Case %d: impossible\n", nc++);

    return 0;
}
