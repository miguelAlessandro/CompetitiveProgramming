#include <iostream>
#include <cstdio>

using namespace::std;

int main(){
    int n;
    scanf("%d", &n);
    (n == 2 || n&1) ? puts("NO") : puts("YES");

    return 0;
}
