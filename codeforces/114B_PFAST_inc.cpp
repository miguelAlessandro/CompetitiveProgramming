#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace::std;

int n, m;
bool adj[20][20];
map<string, int> M;
vector<string> solve;
string N[20];
string A, B;

int main(){

    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> A; 
        M[A] = i;
        N[i] = A;
    }   
    for(int i = 0; i < m; ++i){
        cin >> A >> B;
        adj[M[A]][M[B]] = true;
        adj[M[B]][M[A]] = true;
    }


    int r = 0;
    bool ok;
    for(int i = 0; i < (1<<n); ++i){
        ok = true;
        if(__builtin_popcount(r) < __builtin_popcount(i)){
            for(int j = 0; j < n - 1 and ok; ++j) if(i bitand (1<<j)) 
                for(int k = j + 1; k < n and ok; ++k) if(i bitand (1<<k) and adj[j][k])
                    ok = false;
            if(ok)
                r = i;
        }
    }
        
    for(int i = 0; i < n; ++i)
        if(r bitand (1<<i))
            solve.push_back(N[i]);   
    sort(solve.begin(), solve.end());
    cout << (__builtin_popcount(r)) << endl;
    for(vector<string>::iterator it = solve.begin(); it != solve.end(); ++it)
        cout << *it << endl;

    return 0;
}
