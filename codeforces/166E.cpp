#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int adj[4][4];
int r[4][4], c[4][4], d[4][4];
int n;

void init(){
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(i != j)
				adj[i][j] = 1;

	for(int i = 0; i < 4; ++i)
		r[i][i] = 1;	

}

void mul(int X[4][4], int Y[4][4]){

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j){
			c[i][j] = X[i][j];
			d[i][j] = Y[i][j];
		}

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j){
			X[i][j] = 0;
			for(int k = 0; k < 4; ++k)
				X[i][j] = (X[i][j] + 1LL*c[i][k]*d[k][j])%MOD;
		}
}

void expfast(int n){

	init();
	while(n){
		if(n&1) mul(r, adj);
			
		mul(adj, adj);
		n >>= 1;
	}
}

int main(){

	cin >> n;
	expfast(n);

	cout << r[0][0] << endl;

	return 0;
}
