#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>

using namespace::std;

bool matrix[20][20];
int c, r;
string line[20];

int main(){
    while(getline(cin, line[0]), line[0][0] != 'E'){
        for(int i = 1; i < 15; ++i)
            getline(cin, line[i]);

        int r = 15;
        for(int i = 0; i < (1<<15); ++i){
            for(int j = 0; j < 15; ++j)
                for(int k = 0; k < 15; ++k)
                    matrix[j][k] = line[j][k] == '#';
            
            
            for(int j = 0; j < 15; ++j) if(i & (1<<j))
                for(int k = 0; k < 15; ++k)
                    matrix[j][k] = false;
            c = 0;
            for(int j = 0; j < 15; ++j)
                for(int k = 0; k < 15; ++k)
                    if(matrix[k][j]){
                        ++c;
                        break;
                    }
            if(__builtin_popcount(i) >= c)
                r = min(r, __builtin_popcount(i));
        }
        printf("%d\n", r);
    }

    return 0;
}
