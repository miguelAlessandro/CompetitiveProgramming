#include <iostream>
#include <cstdio>
#include <algorithm>
#define f(x, y, z) for(int x = y; x < z; x++)
#define fe(x, y, z) for(int x = y; x <= z; x++)

using namespace::std;

const int N = 510;

unsigned int A[N], suma = 0;
int n, t;

int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%u", &n);
        
        suma = A[0] = 0u;
        fe(i, 1, n){
            scanf("%u", &A[i]);
            suma += A[i];
        }

        sort(A, A + n + 1);

        unsigned int minimum = suma;
        fe(i, 1, n)
        {
            suma -= (A[i] - A[i-1])*(n - 2*(i-1));
            minimum = min(minimum, suma);
        }   

        printf("%u\n", minimum);
    }

    return 0;
}
