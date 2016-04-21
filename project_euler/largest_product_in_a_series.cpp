#include <iostream>
#include <cstdio>

using namespace std;

long long m[1<<10];

int main(){

    for(int c, t = 0; t < 1000; )
        if(c = getchar(), isdigit(c)){
            t = t + 1;
            m[t] = c - '0';
        }

    /*
    bool espacio = false;
    for(int c = 0,i = 1; i <= 1000; ++i){
        if(m[i] != 0) c = c + 1;
        else c = 0;
        if(c == 30){
            espacio = true;
            break;
        }
    }

    if(espacio){*/ 
        long long prod = 1, maxprod = 1;
        for(int c = 0, k = 1; k <= 1000; ++k){
            if(m[k] != 0 && c < 30) prod *= m[k], c = c + 1;
            else if(m[k] != 0 && c == 30) prod = prod/m[k - 30]*m[k];
            else if(m[k] == 0) prod = 1, c = 0;
            maxprod = max(maxprod, prod);
        }
        printf("%lld\n", maxprod);
    //}
    

    return 0;
}
