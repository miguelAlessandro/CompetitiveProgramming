#include <bits/stdc++.h>

using namespace::std;

int n, p, b;
int sumab, sumap;

int main(){
    
    scanf("%d %d %d", &n, &b, &p);
    sumap = n*p;
    while(n != 1){
        int m = int(log2(n));
        sumab += 2*m*b + m;   
        n -= m;
    }
    printf("%d %d\n", sumab, sumap);

    return 0;
}
