#include <iostream>
#include <cstdio>
#include <set>
#define N 105

using namespace::std;

int n, m, k, a;
set<int> S;

int main( void ){

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &a);
            S.insert(a);
        }
    }

    if(S.size() == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
