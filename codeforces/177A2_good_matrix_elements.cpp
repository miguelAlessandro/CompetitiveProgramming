#include <iostream>
#include <cstdio>

using namespace::std;

int main(){

    int n, x, sum = 0;
    scanf("%d", &n);
    for(int i = -n/2; i <= n/2; ++i)
        for(int j = -n/2; j <= n/2; ++j){
            scanf("%d", &x);
            if(i*i*i*j == j*j*j*i)
                sum += x;        
        }
    printf("%d\n", sum);


    return 0;
}
