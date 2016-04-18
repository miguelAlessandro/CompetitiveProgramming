#include <iostream>
#include <cstdio>

using namespace::std;

int fib[11];

int main(){

    fib[0] = 2;
    fib[1] = 8;
    int suma = 10;
    for(int i = 2; (fib[i] = 4*fib[i-1] + fib[i-2]) <= 4000000; ++i)
        suma += fib[i];

    printf("%d\n", suma);
    return 0;
}
