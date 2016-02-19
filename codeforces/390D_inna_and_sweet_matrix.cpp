#include<bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define N 55

using namespace::std;

int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};

bool visit[N][N];
pair<int, int> p[N][N];
stack<pair<int, int> > V;
int d[N][N],
    n, m, k, cont;

void bfs(int x, int y, int k){

    visit[x][y] = true;
    d[x][y] = 1;
    p[x][x] = make_pair(-1, -1);

    queue<pair<int, int > > Q;
    Q.push(make_pair(x, y));

    while(not Q.empty() and k--)
    {
        pair<int, int> q = Q.front(); Q.pop();                 
        cont += d[q.first][q.second];
        V.push(q);
        f(i, 0, 4){
            int a = q.first + dy[i],
                b = q.second + dx[i];
            if(a >= 0 and b >= 0 and a < n and b < m and not visit[a][b])
            {
                visit[a][b] = true;
                p[a][b] = q;
                d[a][b] = d[q.first][q.second] + 1;               
                Q.push(make_pair(a, b));
            }
        }
    }
}

void path(int x, int y){

    if(x + y != -2)
    {
        pair<int, int> q = p[x][y];   
        path(q.first, q.second);
        printf("(%d,%d) ", x + 1, y + 1);
    }
}



int main( void ){

    scanf("%d %d %d", &n, &m, &k); 

    cont = 0;
    bfs(0, 0, k);

    printf("%d\n", cont);
    
    while(not V.empty()){
        pair<int, int> q = V.top(); V.pop();
        path(q.first, q.second); cout << endl;
    }

    return 0;
}
