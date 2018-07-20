#include <iostream>
#include <cstdio>

using namespace::std;

int t, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%*d %d", &k);
        printf("%d\n", k ^ (k>>1));
    }

    return 0;
}
