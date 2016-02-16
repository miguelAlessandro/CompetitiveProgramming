#include <iostream>
#include <cstdio>

using namespace::std;

int n, r, x;

int main(){

    scanf("%d", &n);
    
    if(n%4==0)
    	r = n;
    else if(n%4==1)
    	r = 1;
    else if(n%4==2)
    	r = n+1;
    else
    	r = 0;

    while(--n){scanf("%d", &x); r ^= x;}
    printf("%d\n", r);

    return 0;
}
