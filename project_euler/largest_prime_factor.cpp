#include <iostream>
#include <cstdio>

using namespace std;

long long n;
int prime[10000] = {2};

long long max_factor(long long n){
    for(int i = 2; i*i < n; ++i)
        while(n%i == 0) 
            n/= i;

    return n;
}


int main(){

    scanf("%lld", &n);
    
    printf("%lld\n", max_factor(n));

    return 0;
}
