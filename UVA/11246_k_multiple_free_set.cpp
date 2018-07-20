#include <iostream>
#include <cstdio>

using namespace::std;

int t, n, k, m, sign, suma;

int main(){
    
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        suma = 0;
        m = 1;
        sign = 1;
        while(n/m){
            suma += sign*n/m;
            sign *= -1;
            m *= k;
        }
        printf("%d\n", suma);
    }
    
    return 0;
}
