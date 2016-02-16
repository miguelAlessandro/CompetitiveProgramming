#include <iostream>
#include <cstdio>
#include <cmath>
#define f(x, y, z) for(int x = y; x < z; ++x)

using namespace::std;

int n, k;

void print(int, int);

void recursive(int n, int floor){

    if(n == 1) printf("X");
    else
    {
        int k = pow(3, n-2);
        if(floor <= k)
        {   
            recursive(n-1, floor);
            print(n, floor);
            recursive(n-1, floor);
        }
        else if(floor <= 2*k)
        {
            for(int i = 0; i < k; ++i) printf(" ");
            recursive(n-1, floor - k);
        }
        else
        {
            recursive(n-1, floor - 2*k);
            print(n, floor - 2*k);
            recursive(n-1, floor - 2*k);
        }
    }
}

void print(int n, int floor){

    int k = pow(3, n-2);
    for(int i = 0; i < k; ++i) printf(" ");
    k /= 3;
    while(k > 0){
        if(floor > k && floor <= 2*k)
        {
            for(int i = 0; i < k; ++i) printf(" ");
            floor -= k;
        }
        else if(floor > 2*k) floor -= 2*k;
        k /= 3;       
    }
}

int main( void ){

    while(scanf("%d", &n) != EOF && n != -1){
        int k = pow(3, n - 1);
        f(i, 1, k + 1)
        {
            recursive(n, i);
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}
