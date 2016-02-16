#include <cstdio>

using namespace::std;

int f91(int n){
    if(n <= 100) return 91;
    return n - 10;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n)
        printf("f91(%d) = %d\n", n, f91(n));       

    return 0;
}   
