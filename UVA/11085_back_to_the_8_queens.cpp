#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define f(x, y, z) for(int x = y; x < z; ++x)

using namespace::std;

int tc(1);
vector<int> row(8), test(8);
vector<vector<int> > solve;

bool place(int r, int c){
    f(prev, 0, c) if(row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) return false;
    return true;
}

void backtracking(int c){
    if(c == 8) solve.push_back(row);
    else f(r, 0, 8) if(place(r, c)){row[c] = r; backtracking(c+1);}   
}

int main(){
    
    backtracking(0);

    while((scanf("%d %d %d %d %d %d %d %d", &test[0], &test[1], &test[2], &test[3], &test[4], &test[5], &test[6], &test[7]) != EOF)){
        
        f(i, 0, 8) test[i]--;

        int minimum(8);
        f(i, 0, int(solve.size())){
            int minimum_test(0);
            f(j, 0, 8) if(solve[i][j] != test[j]) ++minimum_test;
            minimum = min(minimum, minimum_test);
        	if(minimum == 0) break;
        }
        printf("Case %d: %d\n", tc++, minimum);
    }

    return 0;
}
