#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int t;
long long n;

int main(){

    scanf("%d", &t);
    while(scanf("%lld", &n), t--)
        printf("%d\n", int((sqrt(8*n+1)-1)/2));

    return 0;
}
