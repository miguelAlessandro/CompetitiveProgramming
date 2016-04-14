#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace::std;

int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        n = abs(n);
        int i = 0;
        while((i*i + i)/2 < n) ++i;
        while(((i*i + i)/2)%2 != n%2) ++i;
        if(n == 0) puts("3");
        else printf("%d\n", i);
        if(t) puts("");
    }

    return 0;
}   
