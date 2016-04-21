#include <iostream>
#include <cstdio>

using namespace::std;

int n;

int main(){

    scanf("%d", &n);
    printf("%d\n", (n-1)*n*(n+1)/6*(3*n + 2)/2);

    return 0;
}
