#include <bits/stdc++.h>
using namespace std;

const int N = 130;
long long ft[N][N][N];
int n, q, z[6];

void update(int x, int y2, int z2, const int v){
	for(;x<=n; x += x&(-x))
		for(int y = y2; y<=n; y += y&(-y))
			for(int z = z2; z<=n; z += z&(-z))
				ft[x][y][z] += v;
}

long long query(int x, int y2, int z2){
	long long sum = 0;
	for(; x>0; x -= x&(-x))
		for(int y = y2 ; y>0; y -= y&(-y))
			for(int z = z2; z>0; z -= z&(-z))	
				sum += ft[x][y][z];

	return sum;
}



int main(){

	scanf("%d", &n);
	while(scanf("%d", &q), q != 3)
		if(q == 1){
			for(int i = 0; i < 4; ++i) scanf("%d", z+i);
			update(z[0]+1, z[1]+1, z[2]+1, z[3]);
		}
		else{
			for(int i = 0; i < 6; ++i) scanf("%d", z+i);
			long long r = query(z[3]+1, z[4]+1, z[5]+1) 
						- query(z[3]+1, z[4]+1, z[2])
						- query(z[3]+1, z[1], z[5]+1)
						- query(z[0], z[4]+1, z[5]+1)
						+ query(z[0], z[1], z[5]+1)
						+ query(z[0], z[4]+1, z[2])
						+ query(z[3]+1, z[1], z[2])
						- query(z[0], z[1], z[2]);
			printf("%lld\n", r);
		}

	return 0;
}
