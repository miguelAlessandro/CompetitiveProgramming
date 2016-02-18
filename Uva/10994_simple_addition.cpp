#include <cstdio>
#include <iostream>

using namespace::std;

long long K(long long n, long long t){

    long long r = (n + 1)*n/2;
    while(t > 1){
        t /= 10;
        r += 45*n*t;
    }

    return r;
}

long long F(long long n){
    
    if(n == -1) return 0;
    long long r = 0, k = 1;
    while(n > 0){
        r += K(n%10, k);
        
        n /= 10; k *= 10;
    }
    
    return r;
}

int main(){
    
    long long a, b;
    while(scanf("%lld %lld", &a, &b) != EOF && a + b >= 0)      
        printf("%lld\n", F(b) - F(a-1));
    return 0;
}
