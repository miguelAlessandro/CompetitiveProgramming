#include <iostream>
#include <cstdio>

using namespace::std;

int na, nb, k, m, x;
int maxa, minb;

int main(void){

    scanf("%d %d", &na, &nb);
    scanf("%d %d", &k, &m);
    for(int i = 1; i <= na; ++i){ 
        scanf("%d", &x);
        if(i == k) maxa = x;
    }
    for(int i = 0; i < nb; ++i){
        scanf("%d", &x);
        if(i == nb - m) minb = x;
    }
    puts((maxa < minb) ? "YES" : "NO");

    return 0;
}
