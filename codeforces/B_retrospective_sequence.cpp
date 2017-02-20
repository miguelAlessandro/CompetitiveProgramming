#include <iostream>
using namespace std;

const int N = 25;
const long long MOD = 1000000009;
long long a[N][N], r[N][N], b[N][N], c[N][N];
long long d[N], f[N];
int n, C;
long long m;

void init(){

	for(int i = 1; i <= n; ++i)
			r[i][i] = 1;

	for(int i = 1; i <= n-1; ++i)
			a[i][i+1] = 1;			

	for(int i = 1; i <= n; ++i)
		a[n][i] = d[i];
}

void cua(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			b[i][j] = a[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			a[i][j] = 0;
			for(int k = 1; k <= n; ++k)
				a[i][j] = (a[i][j] + b[i][k]*b[k][j])%MOD;
		}	
}


void mul(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			b[i][j] = r[i][j];

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			r[i][j] = 0;
			for(int k = 1; k <= n; ++k)
				r[i][j] = (r[i][j] + b[i][k]*a[k][j])%MOD;
		}
}


void expfast(long long n){
	init();
	while(n > 0){
		if(n&1) mul();
		cua();
		n >>= 1;
	}	
}


int main(){
	
	cin >> n >> m >> C;
	for(int i = 1; i <= n; ++i) cin >> f[i];
	for(int x, i = 0; i < C; ++i){
		cin >> x;
		d[n-x+1] += 1; 
	}

	expfast(m-1);

	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = (ans + f[i]*r[1][i])%MOD;

	cout << ((ans%MOD)+MOD)%MOD << endl; 

	return 0;
}
