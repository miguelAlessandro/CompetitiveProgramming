#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace::std;

int main(){

    int A[5] = {0}, c;
    while((c = getchar()) != '\n')
        if(isdigit(c)) ++A[c - '0'];

    A[2] += A[3];
    A[1] += A[2];

    for(int i = 1; i <= 3; ++i)
        for(;A[1] != A[i+1]; --A[1])
            printf("%d%c", i, (A[1] == 1) ? '\n' : '+');

    return 0;
}
