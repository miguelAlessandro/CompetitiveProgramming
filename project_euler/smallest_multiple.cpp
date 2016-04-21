#include <iostream>
#include <cstdio>

using namespace std;

int n;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){

    scanf("%d", &n);

    int a = 1;
    for(int i = 1; i <= n; ++i)
        a *= i/gcd(i, a);
    
    printf("%d\n", a);

    return 0;
}
