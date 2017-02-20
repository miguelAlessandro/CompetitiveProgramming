#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int ca, cb, n;
int px[N][N], py[N][N], p[N][N];
bool vis[N][N];

void path(int x, int y){
	if(x!=0 or y != 0)
		path(px[x][y], py[x][y]);
	else return;
		
	if(p[x][y] == 0) puts("fill A");
	if(p[x][y] == 1) puts("fill B");
	if(p[x][y] == 2) puts("empty A");
	if(p[x][y] == 3) puts("empty B");
	if(p[x][y] == 4) puts("pour A B");
	if(p[x][y] == 5) puts("pour B A");
}


void bfs(int ca, int cb, int n){
	memset(vis, false, sizeof vis);
	vis[0][0] = true;
	queue<int> Q; Q.push(0); Q.push(0);
	int xf, yf;
	while(not Q.empty()){
		int x = Q.front(); Q.pop();
		int y = Q.front(); Q.pop();
		if(y == n){
			xf = x; yf = y;
			break;
		}

		if(not vis[ca][y]){
			vis[ca][y] = true;
			p[ca][y] = 0;
			px[ca][y] = x;
			py[ca][y] = y;
			Q.push(ca); Q.push(y);
		}		
		if(not vis[x][cb]){
			vis[x][cb] = true;
			p[x][cb] = 1;
			px[x][cb] = x;
			py[x][cb] = y;
			Q.push(x); Q.push(cb);
		}
		if(not vis[0][y]){
			vis[0][y] = true;
			p[0][y] = 2;
			px[0][y] = x;
			py[0][y] = y;
			Q.push(0); Q.push(y);
		}
		if(not vis[x][0]){
			vis[x][0] = true;
			p[x][0] = 3;
			px[x][0] = x;
			py[x][0] = y;
			Q.push(x); Q.push(0);
		}
		if(x >= cb-y and not vis[x-cb+y][cb]){
			vis[x-cb+y][cb] = true;
			p[x-cb+y][cb] = 4;
			px[x-cb+y][cb] = x;
			py[x-cb+y][cb] = y;
			Q.push(x-cb+y); Q.push(cb);
		}
		if(x < cb-y and not vis[0][y+x]){
			vis[0][y+x] = true;
			p[0][y+x] = 4;
			px[0][y+x] = x;
			py[0][y+x] = y;
			Q.push(0); Q.push(y+x);
		}
		if(y >= ca-x and not vis[ca][y-ca+x]){
			vis[ca][y-ca+x] = true;
			p[ca][y-ca+x] = 5;	
			px[ca][y-ca+x] = x;
			py[ca][y-ca+x] = y;
			Q.push(ca); Q.push(y-ca+x);
		}		
		if(y < ca-x and not vis[y+x][0]){
			vis[y+x][0] = true;
			p[y+x][0] = 5;	
			px[y+x][0] = x;
			py[y+x][0] = y; 
			Q.push(y+x); Q.push(0);
		}		
	}
	path(xf, yf);
	puts("success");
}


int main(){

	while(scanf("%d %d %d", &ca, &cb, &n) ==  3)
		bfs(ca, cb, n);		

	return 0;
}
