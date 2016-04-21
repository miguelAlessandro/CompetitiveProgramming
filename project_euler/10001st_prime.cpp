#include <iostream>
#include <cstdio>

using namespace std;

const int N = 10010;

bool notPrime[1000000];
int primest[N];

int criba(){
    int k = 0;
    primest[k++] = 2;
    for(int i = 3; k <= 10001; i += 2){
        bool is_prime = true;
        for(int j = 0; j < k; ++j)
            if(i%primest[j] == 0){
                is_prime = false;
                break;
            }
        if(is_prime)
            primest[k++] = i;
    }
    return k;
}


int main(){
    
    if(criba() > 10001) 
        printf("%d\n", primest[1000]);

    return 0;
}
