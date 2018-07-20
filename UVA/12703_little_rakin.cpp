#include <iostream>
#include <cstdio>

using namespace::std;

int t, n, a, b;
long long fiba[50], fibb[50];

int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        
        fiba[0] = 1;
        fiba[1] = 0;
        for(int i = 2; i <= n; ++i)
            fiba[i] = fiba[i-1] + fiba[i-2];
        
        fibb[0] = 0;
        fibb[1] = 1;
        for(int i = 2; i <= n; ++i)
            fibb[i] = fibb[i-1] + fibb[i-2];

        int h =  max(a, b);
        for(int i = 2; i <= h; ++i){
            int ca = 0, cb = 0;
            while(a%i == 0){
                ++ca; a /= i;
            }
            while(b%i == 0){
                ++cb; b /= i;
            }
            if(ca + cb != 0)
                printf("%d %lld\n", i, ca*fiba[n] + cb*fibb[n]);
        }
        printf("\n");
    } 

    return 0;
}
