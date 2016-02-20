#include <bits/stdc++.h>
#define f(x, y, z)  for(int x  = y; x < z; x++)
#define N 30

using namespace::std;

int t, n;
vector<int> G[N];
bool visit[N];
int d[N];
float c[N];


void bfs(int source)
{
	memset(visit, 0, sizeof visit);
	visit[source] = true;
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
	string A, B, C;

	while(scanf("%d", &n) != EOF)
	{

		for(int j = 0; j < n; j++)
		{
			getline(cin, B);
			stringstream(B) >> C;
			stringstream(B) >> c[C[0] - 'A'];
			stringstream(B) >> A;

			f(i, 0, A.length())
				if(A[i] != '*')
					G[C[0] - 'A'].push_back(A[0] - 'A');
				else
				{
					G[C[0] - 'A'].push_back(26);
					G[26].push_back(A[0] - 'A');
				}
		}
		bfs(26);
		int in;
		float maximum = 0.0;
		f(i, 0, 26)
			if(visit[i])
			{
				float temp = pow(0.95, d[i])*c[i];
				maximum = max(maximum, temp);
				i = in;
			}

		cout << "Import from " << (char)(in + 'A') << endl;
		f(i, 0, N)
			G[i].clear();
	}
	return 0;
}
