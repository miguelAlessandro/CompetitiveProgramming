#include <bits/stdc++.h>
using namespace std;

const int N = 805;
int n, m, q, d, e, f, g;
bool T[N][N];
int hx[2] = {0, -1};
int hy[2] = {-1, -1};
int vx[2] = {-1, -1};
int vy[2] = {0, -1};
int dx[6] = {0, -1, -1, 0, 1, 1};
int dy[6] = {-1, -1, 0, 1, 1, 0};
int dp[N][N], G[N][N], F[N][N];

int main(){

	scanf("%d %d%*c", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			T[i][j] = (getchar() == 'B');
		getchar();
	}

	dp[0][0] = 1;
	for(int i = 1; i < n; ++i)
		dp[i][0] = dp[i-1][0] + (T[i][0] != T[i-1][0]);


	for(int i = 1; i < m; ++i)
		dp[0][i] = dp[0][i-1] + (T[0][i] != T[0][i-1]);
	
	for(int i = 0; i < n; ++i){
		F[i][0] = 1; 
		for(int j = 1; j < m; ++j)
		F[i][j] = F[i][j-1] + (T[0][i] != T[0][i-1]);
	}

	for(int i = 1; i < n; ++i){
		bool color = T[i][0];
		bool save = T[i-1][0] == color;
		int acum = 0;
		for(int j = 1; j < m; ++j)
			if(T[i][j] == color){
				for(int k = 0; k < 2; ++k){
					int ny = i + hy[k];
					int nx = j + hx[k];
					if(T[ny][nx] == color)
						save = true;
				}
				G[i][j] = (not save) + acum;
				dp[i][j] = G[i][j] + dp[i-1][j];
			}
			else{
				if(not save) acum++;	
				color ^= true;		
				save = false;
				for(int k = 0; k < 2; ++k){
					int ny = i + hy[k];
					int nx = j + hx[k];
					if(T[ny][nx] == color)
						save = true;
				}
				G[i][j] = (not save) + acum;
				dp[i][j] = G[i][j] + dp[i-1][j];
			}
	}

	//for(int i = 0; i < n; ++i){
	//	for(int j = 0; j < m; ++j)
	//		cout << dp[i][j] << " ";
	//	cout << endl;
	//}

	scanf("%d", &q);
	while(q--){	
		scanf("%d %d %d %d", &d, &e, &f, &g);
		

	}

	return 0;
}
