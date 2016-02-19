#include <iostream>
#include <cstdio>
#include <climits>
#define N 1000000

using namespace::std;

int A[2*N + 10],
    x, n, B[2*N + 10];

int main(){

    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        A[x] = x;
    }
    
    for(int i = 1; i <= 2*N; ++i)
        if(!A[i]) B[i] = B[i-1];
        else B[i] = A[i];

    int maximum = 0;
    for(int i = 0; i <= N; ++i)
        if(A[i])
            for(int j = 2*i; j <= 2*N; j += i)
                maximum = max(maximum, B[j-1]%i);

    printf("%d\n", maximum);

    return 0;
}
