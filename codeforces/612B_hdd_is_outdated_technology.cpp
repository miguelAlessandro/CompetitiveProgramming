#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace::std;

vector< pair<int, int> > V;

int main(){

    int n, a;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){

        scanf("%d", &a);
        V.push_back(make_pair(a, i));
    }

    sort(V.begin(), V.end());


    long long r = 0;
    for(int i = 1; i < n; ++i)
            r += abs(V[i].second - V[i-1].second);

    printf("%I64d\n", r);

    return 0;
}

