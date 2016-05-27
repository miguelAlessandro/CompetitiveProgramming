#include <iostream>
#include <cstdio>

using namespace::std;

const int N = 110;
bool M[N][N];
int n, row[N], col[N];

int main(){
    scanf("%d%*c", &n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            M[i][j] = (getchar() == 'C');
        getchar();
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {row[i] += M[i][j]; col[j] += M[i][j];}

    int r = 0;
    for(int i = 0; i < n; ++i) r += row[i]*(row[i] - 1) + col[i]*(col[i] - 1);
    printf("%d\n", r>>1);

    return 0;
}

