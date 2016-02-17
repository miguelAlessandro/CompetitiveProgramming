#include <iostream>
#include <vector>
#include <cstdio>

using namespace::std;

int n, t, x;
vector<bool> B(110, false);

int main(){

    scanf("%d", &n);
    
    scanf("%d", &t); while(t--){scanf("%d", &x); B[x-1] = true;}
    scanf("%d", &t); while(t--){scanf("%d", &x); B[x-1] = true;}
    
    for(int i = 0; i < n; ++i) 
        if(!B[i]){
            puts("Oh, my keyboard!");
            return 0;
        }
    puts("I become the guy.");

    return 0;
}
