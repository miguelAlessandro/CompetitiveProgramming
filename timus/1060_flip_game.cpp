#include <iostream>

using namespace::std;

int a[5][5] = {{-4, 16, 0, 1, 4},
               {-3, 0, 1, 2, 5},
               {-2, 1, 2, 3, 6},
               {-1, 2, 3, 7, 16}};

bool visit[(1 << 17) + 5];
int minimo[(1 << 17) + 5];

int dfs(int bitmask){    
    visit[bitmask] = true;
    if(bitmask == 0 || bitmask == ((1 << 16) - 1)) return 0;

    for(int i = 0; i < 4; ++i)
        for(int k = 0; k < 4; ++k){
            int aux = bitmask;
            for(int j = 0; j < 5; ++j){
                int x = a[k][j] + 4*i;
                if(x >= 0 && x < 16)
                    aux ^= (1 << x);
            }
            if(not visit[aux]){
                int r = 1 + dfs(aux);
                minimo[bitmask] = min(minimo[bitmask], r);
            }
            else
                minimo[bitmask] = min(minimo[bitmask], 1 + minimo[aux]);
        }
    return minimo[bitmask];
}

int main(){
 
    string line;
    int estado = 0;
    for(int i = 0; i < 4; ++i){
        cin >> line;
        for(int j = 0; j < 4; ++j)
            if(line[j] == 'b') estado |= (1 << (j + 4*i));
    }
    int r = (1 << 16) + 1;
    minimo[(1<<16) - 1] = minimo[0] = 0;
    for(int i = 1; i < (1 << 16) - 1; ++i)
        minimo[i] = r;
    
    dfs(estado);
    if(minimo[estado] >= (1 << 16) + 1)
        cout << "Impossible" << endl;
    else
        cout << minimo[estado] << endl;

    return 0;
}
