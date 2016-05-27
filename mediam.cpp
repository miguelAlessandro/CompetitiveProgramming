#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100000 + 5;
int v[N];
int n;

bool proof(int x){ 

    int c = 0;
    for(int i = 0; i < n-1; ++i){
        int low = i, upper = n - 1;
        while(low < upper){
            int mid= low + (upper - low + 1)/2;
            if(v[mid] - v[i] <= x) low = mid;
            else upper = mid-1;
        }
        c += (low - i);
    }
    return c <= (n+1)*(n-2)/4; 
}


int main(){
    
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", v + i);
        
        sort(v, v + n); 
        int low = 0, upper = 1000000000;
        while(low < upper){
            int mid = low + (upper - low)>>1;
            if(proof(mid)) low = mid+1;
            else upper = mid;
        }
        printf("%d\n", low);
    }

    return 0;
}
