#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;

const int N = 50;
int t, q, n;
char line[10000];
int  check[N];
int  estate[N][N];
int type[N][N];
int size[N][N];
int bit[N];
int len[N];
int T[N];
int res[N][5];
int color[N];
string x, y;
int w;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d%*c", &q, &n);

		for(int i = 0; i < q; ++i){
			cin.getline(line, 1000);
			//cout << line << endl;
			istringstream nn(line);
			int j = 0;
			bit[i] = 1;
			while(nn >> x){
				if(x == "count"){
					estate[i][j] = 1;
					nn >> y >> w;
					//cout << y << w << endl;
					if(y == "r") type[i][j] = 0;
					if(y == "g") type[i][j] = 1;
					if(y == "b") type[i][j] = 2;
					size[i][j] = w;			
				}
				else{
					estate[i][j] = 0;
					nn >> w >> y;	
					//cout << w << y << endl;
					if(y == "r") type[i][j] = 0;
					if(y == "g") type[i][j] = 1;
					if(y == "b") type[i][j] = 2;
					size[i][j] = w-1;
				}
				nn >> x;
				if(x == "and") bit[i] = 1;
				if(x == "or") bit[i] = 0;
				j++;
			}
			len[i] = j;
			//cout << bit[i] << endl;

			cin.getline(line, 6);
			//cout << line << endl;
			check[i] = (strcmp(line, "yes") == 0);
		}
		
		memset(T, 0, sizeof T);
		memset(res, false, sizeof res);
		for(int h = 0; h < 59049; ++h){
			int x = h;
			for(int j = 0; j < 10; ++j){
				color[j] = x%3;
				T[x%3]++;
				x /= 3;			
			}

	
			int lies = 0;
			for(int j = 0; j < q; ++j){
				bool ok;	
				if(bit[j] == 0)  ok = false;
				else  ok = true;
				for(int k = 0; k < len[j]; ++k){
					if(bit[j] == 1){
						if(estate[j][k]) ok = ok and (size[j][k] == T[type[j][k]]);
						else ok = ok and (color[size[j][k]] == type[j][k]);
					}else if(bit[j] == 0){
						if(estate[j][k]) ok = ok or (size[j][k] == T[type[j][k]]);
						else ok = ok or (color[size[j][k]] == type[j][k]);
					}
				}

				lies += (ok != check[j]);	
			}
			
			if(lies == n)
				for(int j = 0; j < 10; ++j) res[j][color[j]] = true;
		}

		for(int k = 0; k < 10; ++k){
			if(res[k][0]) putchar('r');
			if(res[k][1]) putchar('g');
			if(res[k][2]) putchar('b');
			if(k == 9) putchar('\n');
			else putchar(' ');
		}
	}

	return 0;
}
