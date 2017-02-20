#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int P = 1299827;
const long long M = 5000000000053;
const long long Q = 3367900313LL;
int h, n, m, q, k, c, len, ex[N];
char s[N];
int r[N], l[N], f[N];
map<long long, int> H[P+10];

long long mul(long long a, long long b){
	long long r = 0;
	while(b){
		if(b&1) r = (r+a)%M;
		a = (a+a)%M;
		b >>= 1;
	}
	return r;
}

int main(){

	scanf("%d %d %d %d%*c", &n, &m, &q, &k);
	h = 0;
	scanf("%s", s); getchar();
	//puts(s);
	for(int i = 0; i < k; ++i)
		h = (mul(h, Q) + s[i])%M;

	ex[0] = 1;
	for(int i = 1; i <= n; ++i)
		ex[i] = mul(ex[i-1], Q);		

	H[h%P][h]++;
	for(int i = k; i < n; ++i){
		h = (mul((h - mul(s[i-k], ex[k-1])), Q) + s[i])%M;	
		if(h < 0) h += M;
		H[h%P][h]++;
	}

	for(int i = 1; i <= m; ++i)
		scanf("%d %d%*c", l+i, r+i);

	while(q--){

		int a, b;
		for(int i = 1; i <= k; ++i)
			f[i] = (mul(f[i-1], Q) + getchar())%M;

		int ans = 0;
		scanf("%d %d%*c", &a, &b);
		for(int i = a; i <= b; ++i){
			int ha = (f[r[i] + 1] - mul(f[l[i]], ex[r[i]-l[i]+1]))%M;
			if(ha < 0) ha += M;
			if(H[ha%P].find(ha) != H[ha%P].end())			
				ans += H[ha%P][ha];
		}
		printf("%d\n", ans);
	}	

	return 0;
}
