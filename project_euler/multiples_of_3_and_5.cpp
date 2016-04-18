#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main(){

    scanf("%d", &n); //principio de inclusion y exclusion para la diferencia extricta
    int solve = 3*((n-1)/3)*((n-1)/3 + 1) + 5*((n-1)/5)*((n-1)/5 + 1) 
                - 15*((n-1)/15)*((n-1)/15 + 1);
    printf("%d\n", solve>>1);

    return 0;
}
