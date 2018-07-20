#include <iostream>
#include <cstdio>
#include <cstring>

using namespace::std;

int n;
bool solution, map[11];

bool mapeo(int n, int m){

    memset(map, false, sizeof map);
    if(n < 10000 && m < 10000) return false;
    if(n < 10000 || m < 10000) map[0] = true;
    while(n > 0){
        if(map[n%10]) return false;
        map[n%10] = true;
        n /= 10;
    }
    while(m > 0){
        if(map[m%10]) return false;
        map[m%10] = true;
        m /= 10;
    }
    return true;
}

int main(){

    int nc = 0;
    while(scanf("%d", &n), n){
        solution = false;
        if(nc++) puts("");
        solution = false;
        for(int i = 1234; i < 98765; ++i)
            if(mapeo(i, n*i)){
                solution = true;
                if(i < 10000)
                    printf("%d / 0%d = %d\n", n*i, i, n);
                else
                    printf("%d / %d = %d\n", n*i, i, n);                   
            }

        if(not solution)
            printf("There are no solutions for %d.\n", n);
    }

    return 0;
}
