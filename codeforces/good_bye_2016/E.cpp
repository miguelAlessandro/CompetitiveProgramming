#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int s[N];
int next[5][N], rank[3][N];
int v[] = {0, 1, 2};
int n, q;

int main(){

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%1d", s+i);
		rank[0][i] = (s[i] == 6) + rank[0][i-1];
		rank[1][i] = (s[i] == 7) + rank[1][i-1];
	}

	for(int i = n; i >= 1; --i)
		for(int j = 0; j < 3; ++j){
			if(i == n){
				if(s[i] == v[j]) next[j][i] = i;
				else next[j][i] = -1;
			}	
			else{
				if(s[i] == v[j]) next[j][i] = i;
				else next[j][i] = next[j][i+1];
			}
		}

	int a, b;
	while(q--){
		scanf("%d %d", &a, &b);	
		int dos = -1, cero  = -1, uno = -1, seis = -1, siete = -1;	
		
		dos = next[2][a];
		if(dos != -1 and dos < b) cero = next[0][dos+1];
		if(cero != -1 and cero < b) uno = next[1][cero+1];
		if(uno != -1 and uno < b){
			seis = rank[0][b] - rank[0][uno];
			siete = rank[1][b] - rank[1][uno];
		}

		if(cero != -1 and uno != -1 and dos != -1 and siete != 0) printf("%d\n", seis);
		else puts("-1");
	}

	return 0;
}
