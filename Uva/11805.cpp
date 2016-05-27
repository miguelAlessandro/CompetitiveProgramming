#include <iostream>
#include <cstdio>
using namespace std;
int t, n, k, p, nc = 1;

int main(){

    scanf("%d", &t);
    while(scanf("%d %d %d", &n, &k, &p), t--)
        (p+k)%n ?
            printf("Case %d: %d\n", nc++, (p + k)%n):
            printf("Case %d: %d\n", nc++, n);        

    return 0;
}
