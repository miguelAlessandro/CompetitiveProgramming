#include <iostream>
#include <cstdio>
using namespace std;

long long n;
int t;

bool proof(long long mid){
    return mid*(mid + 1)/2 <= n;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        int low = 0, upper = 1000000000;
        while(low < upper){
            int mid = (low + upper + 1)/2;
            if(proof(mid)) low = mid;
            else upper = mid-1;
        }
        printf("%d\n", low);
    }

    return 0;
}
