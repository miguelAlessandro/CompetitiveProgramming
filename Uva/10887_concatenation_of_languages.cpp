#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace::std;

int t, n, m;
string A;
vector<string> S1, S2;
set<string> S;

int main(){

    scanf("%d", &t);
    for(int j = 1; j <= t; ++j){
        scanf("%d %d%*c", &n, &m);
        
        for(int i = 0; i < n; ++i){
            getline(cin, A);
            S1.push_back(A);
        }
        for(int i = 0; i < m; ++i){
            getline(cin, A);
            S2.push_back(A);
        }
        for(int i = 0; i < n; ++i)
            for(int l = 0; l < m; ++l){
                A = S1[i] + S2[l];
                S.insert(A);
            }

        printf("Case %d: %d\n",j, (int)S.size());
        
        S1.clear(); S2.clear(); S.clear();
    }   

    return 0;
}
