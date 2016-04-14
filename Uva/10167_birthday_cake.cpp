#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>

using namespace::std;

int Y[105], X[105];
int n;

int main(){
    int nc = 0;
    while(scanf("%d", &n), n){
        for(int i = 0; i < 2*n; ++i) scanf("%d %d", X + i, Y + i);
        bool nok = true;
        for(int i = -500; i <= 500 && nok; ++i)
            for(int j = -500; j <= 500 && nok; ++j){
                int left = 0, right = 0;
                for(int k = 0; k < 2*n; ++k)
                    if(i*X[k] + j*Y[k] < 0) ++left;
                    else if(i*X[k] + j*Y[k] > 0) ++right;
                if(left == n && right == n){
                    printf("%d %d\n", i, j);
                    nok = false;
                }
            }
    }

   return 0;
}
