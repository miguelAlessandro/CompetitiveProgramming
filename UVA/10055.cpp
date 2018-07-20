#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a, b;

int main(){

    while(scanf("%lld %lld", &a, &b) == 2)
        printf("%lld\n", abs(a-b));

    return 0;
}
