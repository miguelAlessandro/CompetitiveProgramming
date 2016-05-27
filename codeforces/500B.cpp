#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n;
bool A[N][N];
priority_queue< int, vector<int>, greater<int> > Q[N];

int p[N];
int color[N];


int dfs(int x, int T){
    color[x] = T;
    Q[T].push(p[x]);
    for(int i = 0; i < n; ++i)
        if(A[x][i] and not color[i])
            dfs(i, T);
}


int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%*c", p+i);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            A[i][j] = getchar() == '1';
        getchar();
    }

    int t = 1;
    for(int i = 0; i < n; ++i)
        if(not color[i])
            dfs(i, t++);

    for(int i = 0; i < n; ++i){
        printf("%d ", Q[color[i]].top());
        Q[color[i]].pop();
    }
    puts("");

    return 0;
}
