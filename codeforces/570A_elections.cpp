#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
int n, m;
int a[N][N];
int w[N], p[N], maxi[N];

int main(){
	
	cin >> m >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];

	memset(p, -1, sizeof p);	

	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(a[i][j] > p[i]){
				p[i] = a[i][j];
				w[i] = j;
			}

	
	for(int i = 0; i < n; ++i)
		maxi[w[i]]+=1;
	
	int r = 0;
	for(int i = 0; i < m; ++i)
		r = max(maxi[i], r);

	for(int i = 0; i < m; ++i)
		if(r == maxi[i]){
			r = i+1;
			break;
		}

	cout << r << endl;

	return 0;
}
