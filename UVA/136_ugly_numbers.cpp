#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace::std;

vector<long long> set;

int main(){
    for(long long i = 1; i < 10000000000; i *= 2)
        for(long long j = 1; j < 10000000000; j *= 3) 
            if(i*j <= 10000000000)
                for(long long k = 1; k < 10000000000; k *= 5) 
                    if(i*j*k <= 10000000000)
                        set.push_back(i*j*k);
                    else break;
            else break;

    sort(set.begin(), set.end());
//    set.resize(unique(set.begin(), set.end()) - set.begin());
    
    printf("The 1500'th ugly number is %lld.\n", set[1499]);

    return 0;
}
