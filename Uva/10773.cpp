#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int t, d, v, u;

int main(){
    
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        scanf("%d %d %d", &d, &v, &u);
        if(v == u || v == 0 || v > u)
            printf("Case %d: can't determine\n", i);
        else
            printf("Case %d: %.3f\n", i, d*(-1.0/u + 1.0/sqrt(u*u - v*v)));
    }

    return 0;
}
