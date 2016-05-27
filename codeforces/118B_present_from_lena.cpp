#include <iostream>
#include <cstdio>
#define ABS(X) (((X)>=0) ? (X) : (-X))

using namespace::std;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = -n; i <= n; ++i)
        for(int j = -n; j + ABS(i) <= n; ++j)
            if(ABS(i) + ABS(j) <= n)
                printf("%d%c", n - ABS(i) - ABS(j), j + ABS(i) == n ? '\n' : ' ');
            else
                printf("  ");

    return 0;
}
