#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 27;
int n, m;
char s[N][N];
int disA[N][N];
bool visA[N][N], visG[N][N];
set< ii > ss;
queue<int> QA, QG;
const int dx[] = {1, 0, -1, 0},
		  dy[] = {0, 1, 0, -1};

bool proof(int a, int b){
	return a >= 0 and a < n and b >= 0 and b < m and s[a][b] != 'X';
}

int bfs(int x, int y, int x1, int y1){
	QA.push(x); QA.push(y);
	QG.push(x1); QG.push(y1);
	visA[x][y] = true;
	visG[x1][y1] = true;
	disA[x][y] = 0;
	ss.insert(ii(x1, y1));
	int c1 = 1, c2 = 1;

	while(not QA.empty()){
		
		int nc2 = 0;
		for(int l = 0; l < c2; ++l){
			int xG = QG.front(); QG.pop();
			int yG = QG.front(); QG.pop();
			ss.erase(ii(xG, yG));
			visG[xG][yG] = false;
			for(int a, b, i = 0; i < 4; ++i){
				a = xG+dx[i];
				b = yG+dy[i];
				if(proof(a, b) and not visG[a][b]){
					visG[a][b] = true;
					QG.push(a);
					QG.push(b);
					ss.insert(ii(a, b));
					nc2++;
				}
			}
		}
		c2 = nc2;
		
		int nc1 = 0;
		for(int l = 0; l < c1; ++l){
			int xA = QA.front(); QA.pop();
			int yA = QA.front(); QA.pop();
		
			if(s[xA][yA] == 'P') return disA[xA][yA];

			for(int a, b, i = 0; i < 4; ++i){
				a = xA + dx[i];
				b = yA + dy[i];
				if(proof(a, b) and not visA[a][b] and ss.find(ii(a, b)) == ss.end()){
					visA[a][b] = true;
					disA[a][b] = disA[xA][yA] + 1;
					QA.push(a);
					QA.push(b);
					nc1++;
				}	
			}
		}
		c1 = nc1;
	}

	return -1;
}


int main(){

	int xG, yG, xA, yA;

	scanf("%d %d%*c", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s", s[i]);
		for(int j = 0; j < m; ++j)
			if(s[i][j] == 'A') xA = i, yA = j;
			else if(s[i][j] == 'G') xG = i, yG = j;
	}
	
	printf("%d\n", bfs(xA, yA, xG, yG));

	return 0;
}
