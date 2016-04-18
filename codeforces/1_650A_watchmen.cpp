#include <iostream>
#include <cstdio>
#include <map>

using namespace::std;

map<int, long long> X, Y;
map<pair<int, int>, long long> XY;
int n;

int main(){

    scanf("%d", &n);
    for(int x, y, i = 0; i < n; ++i){
        scanf("%d %d", &x, &y);
        X[x]++;
        Y[y]++;
        XY[make_pair(x, y)]++;
    }
    long long suma = 0;
    for(auto it : X) suma += it.second*(it.second - 1);
    for(auto it : Y) suma += it.second*(it.second - 1);
    for(auto it : XY) suma -= it.second*(it.second - 1);

    printf("%I64d\n", suma>>1);
    
    return 0;
}
