#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;

bool not_prime[(1<<15) + 5];
vector<int> prime;
int n, cont;

void eratostenes(int n){
    not_prime[0] = not_prime[1] = true;
    for(int i = 4; i <= n; i += 2) not_prime[i] = true;
    for(int i = 3; i*i <= n; i += 2)
        if(not not_prime[i])
            for(int j = i*i; j <= n; j += 2*i)
                not_prime[j] = true;

    for(int i = 2; i <= n; ++i)
        if(!not_prime[i])
            prime.push_back(i);
}


int main(){
    eratostenes(1<<15);
    while(scanf("%d", &n), n){
        cont = 0;
        for(int i = 0; i <= n/2 && i < prime.size() && prime[i] <= n/2; ++i)
            if(not not_prime[n-prime[i]])
                ++cont;
            
        printf("%d\n", cont);
    }

    return 0;
}
