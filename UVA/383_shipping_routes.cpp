#include <bits/stdc++.h>
#define f(x, y, z)  for(int x  = y; x < z; x++)
#define N 50

using namespace::std;

int t, n, m, q;


map<string, int> M;
vector<int> G[N];
bool visit[N];
int d[N];


void bfs(int source)
{
	memset(visit, 0, sizeof visit);
	visit[source] = false;
	d[source] = 0;
	queue<int> Q;
	Q.push(source);
	while(!Q.empty())
	{
		int q =  Q.front(); Q.pop();
		f(i, 0, G[q].size())
		{
			int s = G[q][i];
			if(!visit[s])
			{
				visit[s] = true;
				d[s] = d[q] + 1;
				Q.push(s);
			}
		}
	}
}


int main( void )
{
	int costo;
	cin >> t;
	cout << "SHIPPING ROUTES OUTPUT\n" << endl; 
	f(k, 0, t)
	{
		string a, b;
		cin >> n >> m >> q;
		f(i, 0, n)
		{
			cin >> a;
			M[a] = i;
		}
		f(i, 0, m)
		{
			cin >> a >> b;
			G[M.find(a)->second].push_back(M.find(b)->second);
			G[M.find(b)->second].push_back(M.find(a)->second);
		}
		cout << "DATA SET  " << k + 1 << "\n" << endl;
 		f(i, 0, q)
		{
			cin >> costo;
			cin >> a >> b;
			bfs(M.find(a)->second);
			if(!visit[M.find(b)->second])
				cout << "NO SHIPMENT POSSIBLE" << endl;
			else
				cout << "$" << costo*100*d[M.find(b)->second] << endl;
		}
		cout << endl;
		M.clear();
		f(i, 0, n)
			G[i].clear();
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
