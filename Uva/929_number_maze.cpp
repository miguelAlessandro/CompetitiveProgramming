#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define pb push_back
#define clr(X, A) memset(X, A, sizeof X)
#define N 1005
#define INF 1000000000
using namespace::std;

typedef pair<int, pair<int, int> > iii;
typedef pair<int, int> ii;


int M[N][N];
int d[N][N];
int	dx[] = {1, 0, -1, 0},
		dy[] = {0, -1, 0, 1};
int t, n, m;


void dijkstra()
{
	clr(d, 0x3f);
	priority_queue< iii, vector<iii>, greater<iii> > Q;
	d[0][0] = M[0][0];
	Q.push(iii(d[0][0], ii(0, 0)));
	while(!Q.empty())
	{
		iii q = Q.top(); Q.pop();
        
        int w = q.first;
        ii u = q.second;

        if(d[u.first][u.second] == w)
            f(i, 0, 4)
		    {
			    int a = u.first + dy[i], b = u.second + dx[i];
			    if(a >= 0 && b >= 0 && a < n && b < m)
			    {
                    int v = M[a][b];
				    if(d[u.first][u.second] + v < d[a][b])
				    {
					    d[a][b] = d[u.first][u.second] + v;
					    Q.push(iii(d[a][b], ii(a, b)));
				    }
			    }
		    }
	}
}

int main( void )
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%*c%d", &n, &m);
		
		f(i, 0, n)
			f(j, 0, m)
				scanf("%d", &M[i][j]);

		dijkstra();
		printf("%d\n", d[n-1][m-1]);
	}		
	return 0;
}
