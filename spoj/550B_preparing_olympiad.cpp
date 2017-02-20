#include <iostream>
#include <cstdio>

using namespace::std;

const int N = 16;
int n, l, r, x, c[N];

void backtracking(int bitmask, int& solve){
    int p = bitmask, lsone, maximo = 0, minimo = 1000000001, suma = 0, elements = 0;
    for(int i = 0; i < n; ++i)
        if(bitmask & (1<<i)){
            maximo = max(maximo, c[i]);
            minimo = min(minimo, c[i]);
            suma += c[i];
            elements++;
        }
    if(suma >= l && suma <= r && elements > 1 && maximo - minimo >= x) ++solve;
    if(bitmask == (1<<n) - 1) return;
    backtracking(bitmask + 1, solve);
}

int main(){

    scanf("%d %d %d %d", &n, &l, &r, &x);
    for(int i = 0; i < n; ++i) scanf("%d", &c[i]);
    int s = 0;
    backtracking(1, s);   
    printf("%d\n", s);
    return 0;
}
