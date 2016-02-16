#include <iostream>
#include <cstdio>
#define N 100005

using namespace std;

int v[N],
    n;

int main( void ){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    long long joy = 0;
    for(int i = 0; i < n; i++)
    {
        long long a;
        scanf("%lld", &a);
        if(a <= 2*v[i] && a >= 2)
            joy += (a/2)*(a - a/2);
        else
            joy--;
    }

    printf("%I64d\n", joy);

    return 0;
}
