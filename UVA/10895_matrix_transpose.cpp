#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 100005

using namespace::std;

int m, n, p, r;
vector<int> Matrix[N];
vector<int> col;

int main(){

    int nc = 0;
    while(scanf("%d %d", &m, &n) == 2){
        for(int i = 1; i <= m; ++i){
            scanf("%d", &r); col.resize(r);
            for(int j = 0; j < r; ++j)
                scanf("%d", &col[j]);
            for(int j = 0; j < r; ++j){
                scanf("%d", &p);
                if(p >= 0)
                    Matrix[col[j]].push_back(100000*i + p); 
                else
                    Matrix[col[j]].push_back(-100000*i + p);
            }
        }
        printf("%d %d\n", n, m);
        for(int i = 1; i <= n; ++i){
            int sz = Matrix[i].size();
            printf("%d", sz);
            for(int j = 0; j < sz; ++j)
                printf(" %d", abs(Matrix[i][j]/100000));
            puts("");
            for(int j = 0; j < sz; ++j){
                if(j) putchar(' ');
                printf("%d", Matrix[i][j]%100000);
            }
            puts("");
            Matrix[i].clear();
        }
    }

    return 0;
}
