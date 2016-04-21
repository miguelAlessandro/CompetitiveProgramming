#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 200000;

bool notPrime[N];
vector<int> primest;

void criba(){
    
    primest.push_back(2);
    for(int i = 3; i <= N; i += 2)
        if(not notPrime[i]){
            for(int j = 3*i; j <= N; j += 2*i)
                notPrime[j] = true;
            primest.push_back(i);
        }
}



int main(){

    criba();
    printf("%d\n", primest[10000]);

    return 0;
}
