#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define pb push_back
#define clr(X, A) memset(X, A, sizeof X)
#define N 105

using namespace::std;

struct nodo{
	int v, 
	    w;
	nodo() {}
	nodo(int vv, int ww): v(vv), w(ww) {}
};
vector<nodo> G[N];
int d[N];
long long cont;
int t, n, e, m, T;


bool operator<(nodo a, nodo b){
	return a.w < b.w;
}

void dijkstra(int source)
{
	clr(d, 1);
	priority_queue<nodo> Q;
	d[source] = 0;
	Q.push(nodo(source, 0));
	while(!Q.empty()){
		nodo q = Q.top(); Q.pop();
		f(i, 0, G[q.v].size()){
			nodo s = G[q.v][i];
			int temp = d[q.v] + s.w;
			if(temp < d[s.v]){
				d[s.v] = temp;
				Q.push(nodo(s.v, temp));
			}
		}
	}
}

int main( void )
{
	cin >> t;
	for(int j = 0; j < t; ++j)
	{
		cin >> n >> e >> T >> m;
		
		f(i, 0, m)
		{
			int a, b, w;
			cin >> a >> b >> w;
			--a; --b;
			G[b].pb(nodo(a, w));
		}
		--e;
		dijkstra(e);
		cont = 0;
		f(i, 0, n)
			if(d[i] <= T)
				cont++;
		
        if(j != 0 )
			cout << endl;

		cout << cont << endl;
		
        f(i, 0, n)
		    G[i].clear();
	}		
	return 0;
}
