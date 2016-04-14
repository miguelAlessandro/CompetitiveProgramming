#include <iostream>
#include <cstdio>

using namespace::std;

int t, n, k, l, r, p;

int main(){
    scanf("%d", &t);
    while(t--){
        l = 1; r = 3;
        scanf("%d %d", &n, &k);
        int rpta = 0;
        for(int i = 0; i < n; ++i)
           if((k + 1)%(1 << (i+2)) > (l << i) && (k + 1)%(1 << (i + 2)) <= (r << i))
                rpta |= (1 << i);
        printf("%d\n", rpta);
    }

    return 0;
}
