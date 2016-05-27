#include <iostream>
#include <cstdio>

using namespace std;
int n;

int main(){
    
    while(scanf("%d", &n), n)
        (n == 1 or (n-2)%3 == 0) ? puts("NO") : puts("YES");


    return 0;
}
