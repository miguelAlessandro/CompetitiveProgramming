#include <iostream>
#include <cstdio>

using namespace::std;


long long iterative( long long n){

    if(n == -1) return -1;
    long long aux = n,
              sum = 0;
    int l = 1, mod = 0;

    while(aux >= 10){
        
        mod = aux%10;
        aux /= 10;
        
        sum += aux*l;
        if(!mod) sum += n%l - l + 1;
        
        l *= 10;
    }
    return sum;
}


int main( void ){
    
    long long A, B;
    while( scanf("%lld %lld", &A, &B) != EOF && A >= 0) 
        printf("%lld\n", iterative(B) - iterative(A-1));

    return 0;
}
