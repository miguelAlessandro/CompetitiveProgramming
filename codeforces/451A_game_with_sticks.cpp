#include <iostream>
#include <cstdio>

using namespace::std;

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    if(min(n, m)&1) puts("Akshat");
    else puts("Malvika");

    return 0;
}
