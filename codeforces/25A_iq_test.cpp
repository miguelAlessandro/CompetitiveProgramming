#include <iostream>

using namespace::std;

int main(){

    int n, impares = 0, pares = 0, upar = 0, uimp = 0, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        if(x&1)
            ++impares, uímp = i; 
        else
            ++pares, upar = i;
        if(impares > 1 && pares == 1){
            printf("%d\n", upar);
            return 0;   
        }
        else if(pares > 1 && impares == 1){
            printf("%d\n", uimp);
            return 0;
        }
    }

    return 0;
}
