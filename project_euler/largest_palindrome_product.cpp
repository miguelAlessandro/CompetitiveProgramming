#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int maxi = 0;
    for(int i = 999; i >= 100; --i)
        for(int j = ((i%11 == 0) ? 999 : 990); j >= i; j -= ((i%11 == 0) ? 1 : 11)){
            if(i*j <= maxi) continue;
            int aux = 0, inv = i*j;
            while(inv){
                aux = aux*10 + inv%10;
                inv /= 10;
            }
            if(aux == i*j) maxi = max(maxi, aux);
        }

    printf("%d\n", maxi);

    return 0;
}
