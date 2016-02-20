#include <iostream>
#include <cstdio>
#include <vector>
#define f(x, y, z) for(int x = y; x < z; ++x)

using namespace::std;

int n, m, suma_r;
vector<int> r, v, a;


void backtracking(vector<int>& solve, vector<int>& set, long long suma, int indice){

    if(suma > n) return;
    if(suma > suma_r || suma == suma_r && solve.size() >= r.size()) r = solve, suma_r = suma;
    if(indice == m) return;

    solve.push_back(indice);
    backtracking(solve, set, suma + set[indice] , indice + 1);
    solve.pop_back();
    backtracking(solve, set, suma               , indice + 1);
}


int main(){

    while(scanf("%d %d", &n, &m) != EOF){

        r.resize(0); a.resize(0); suma_r = 0; v.resize(m);
        f(i, 0, m) scanf("%d", &v[i]);
    
        backtracking(a, v, 0, 0);       
        
        f(i, 0, int(r.size())) printf("%d ", v[r[i]]);
        printf("sum:%d\n", suma_r);
    }

    return 0;
}   
