#include <iostream>
#include <cstdio>

using namespace::std;

int main(){

    int i = 1, n;
    while(scanf("%d", &n), n) printf("Case %d: %d\n", i++, n>>1);

    return 0;
}
