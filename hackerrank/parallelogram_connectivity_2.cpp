#include <bits/stdc++.h>
using namespace std;

const int N = 805;
int n, m, q, d, e, f, g;
bool T[N][N];
int hx[2] = {0, -1};
int hy[2] = {-1, -1};
int U[N][N], NS[N][N], SS[N][N], F[N];
int NE[N][N];

int main(){

	scanf("%d %d%*c", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = m-1; j >= 0; --j)
			T[i][j] = (getchar() == 'B');
		getchar();
	}

	//for(int i = 0; i < n; ++i){
	//	for(int j = 0; j < m; ++j)
	//		cout << T[i][j] << " ";
	//	cout << endl;
	//}

	for(int i = 1; i < n; ++i){
		NS[i][0] = (T[i][0] != T[i-1][0]);
		SS[i][0] = (T[i][0] == T[i-1][0]);
		if(not SS[i][0]) U[i][0] = -1;
		else U[i][0] = 0;

		if(m > 1){
			if(T[i][1] != T[i][0]) NE[i][0] = 0;
		} 
		else NE[i][0] = 0;  

		for(int j = 1; j < m; ++j){
			
			int save = false;	
			int in = -1;
			for(int k = 1; k >= 0; --k){
				int nx = j + hx[k];
				int ny = i + hy[k];
				if(T[ny][nx] == T[i][j]){
					save = true;
					in = nx;
				}
			}
	
			if(T[i][j-1] == T[i][j]){
				SS[i][j] = (save or SS[i][j-1]);					
				U[i][j] = max(U[i][j-1], in);
				if(save){
					if(SS[i][j-1]) NS[i][j] = NS[i][j-1];
					else NS[i][j] = NS[i][j-1] - 1;
				}	
				else
					NS[i][j] = NS[i][j-1];
			}
			else{
				SS[i][j] = save;
				U[i][j] = in;
				NS[i][j] = (not save) + NS[i][j-1];
			}

			if(j+1 == m or T[i][j] != T[i][j+1]){
				int k = j;
				while(k >= 0 and T[i][k] == T[i][j]) NE[i][k--] = j;
			} 
		}
	}

	//for(int i = 1; i < n; ++i){
	//	for(int j = 0; j < m; ++j)
	//		cout << NS[i][j] << " ";
	//	cout << endl;
	//}

	scanf("%d", &q);
	while(q--){	
		scanf("%d %d %d %d", &d, &e, &f, &g);
		e = m - e + 1;
		g = m - g + 1;
		swap(e, g);	

		F[e-1] = 1; 
		for(int i = e; i < g; ++i)
			F[i] = F[i-1] + (T[d-1][i] != T[d-1][i-1]);
		
		//for(int i = e-1; i < g; ++i)		
		//	cout << F[i] << " ";
		//cout << endl;

		int ans = F[g-1];
		if(e == 1){
			for(int i = d; i < f; ++i)
				ans += NS[i][g-1];
		}
		else{
			int l;
			for(int i = d; i < f; ++i){
				int enl;
				if(T[i][e-1] == T[i][e-2]){
					l = NE[i][e-1];
				
					if(SS[i][e-2]){
						if(U[i][e-2] == U[i][l]) enl = NS[i][g-1] - NS[i][e-2] + 1; 	
						else enl = NS[i][g-1] - NS[i][e-2];
					}	
					else enl = NS[i][g-1] - NS[i][e-2] + 1;
				}
				else{
					l = NE[i][e-1];
					
					if(SS[i][l]){ 
						if(U[i][l] >= e-1) enl = NS[i][g-1] - NS[i][e-2];					
						else enl = NS[i][g-1] - NS[i][e-2] + 1;
					}
					else enl = NS[i][g-1] - NS[i][e-2];
				}
				ans += enl;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
