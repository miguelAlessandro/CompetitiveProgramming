#include <bits/stdc++.h>

using namespace::std;

int n, Ncifras;


int main(){

    scanf("%d", &n);
    Ncifras = int(log10(n)) + 1;
    int r = 0;
    for(int i = 0; i < Ncifras; ++i){    
        if(n%10 == 7) r |= (1 << i);
        n /= 10;
    }

    printf("%d\n", (1<<Ncifras) + r - 1);

    return 0;
}
