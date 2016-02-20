#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define clr(X, A) memset(X, A, sizeof X)
#define pb push_back
#define N 105

using namespace::std;
int l = 0;


struct nodo{
	int v, k;
	nodo() {}
	nodo(int vv, int kk): v(vv), k(kk) {}
};

vector<int> G[N/2];
vector<nodo> H[N];
bool visit[N];
int d[N],
	cont,
	c, m, h;

int search(int key)
{
	f(i, 0, H[key%N].size())
		if(key == H[key%N][i].v)
			return H[key%N][i].k;
	return -1;	
}

void insert(int a, int b)
{
	int k = search(a);
	if(k != -1)
		G[k].pb(b);
	else
	{
		H[a%N].pb(nodo(a, l));
		G[l++].pb(b);
	}
}

void bfs(int source)
{
	visit[search(source)] = true;
	d[search(source)] = 0;
	queue<int> Q;
	Q.push(source);
	while(!Q.empty())
	{
		int q = search(Q.front()); Q.pop();
		f(i, 0, G[q].size())
		{
			int s = search(G[q][i]);
			if(!visit[s])
			{
				visit[s] = true;
				d[s] = d[q] + 1;
				if(d[s] <= h)
					cont++;
				Q.push(G[q][i]);
			}
		}
	}		
}


int main(void)
{
	int t = 1;
	while((cin >> m) && m != 0)
	{
		l = 0;
		f(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			insert(a, b);
			insert(b, a);
		}
		while((cin >> c >> h) && c + h != 0)
		{
			cont = 1;
			if(search(c) == -1)
				cont = 0;
			else
				bfs(c);
			cout << "Case " <<  t << ": " << l - cont << " nodes not reachable from node " << c << " with TTL = " << h << "." << endl;
			t++;
			clr(d, 0);
			clr(visit, false);
		}
		f(i, 0, N)
			 H[i].clear();
		f(i, 0, N/2)
			G[i].clear();
	}
}
