#include <iostream>
#include <cstdio>
using namespace std;
int n, m;

int main(){
    while(scanf("%d %d", &n, &m) == 2)
        printf("%d\n", m^n);

    return 0;
}
