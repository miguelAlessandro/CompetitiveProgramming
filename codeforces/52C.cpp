#include <bits/stdc++.h>
using namespace std;

const int N = 800002;
long long Min[N];
long long lazy[N];
int lo[N], hi[N];
int A[N>>2];
int n, m;

void update(int i){
	Min[i] = min(Min[i<<1] + lazy[i<<1], Min[(i<<1)|1] + lazy[(i<<1)|1]);
}

void prop(int i){
	lazy[i<<1] += lazy[i];
	lazy[(i<<1)|1] += lazy[i];
	lazy[i] = 0;
}

void init(int i, int a, int b){
	
	lo[i] = a;
	hi[i] = b;
	if(a == b){
		Min[i] = A[a];
		return;
	}

	int m = (a+b)>>1;
	init(i<<1, a, m);
	init((i<<1)|1, m+1, b);
	
	update(i);
}

void increment(int i, int a, int b, int val){

	if(b < lo[i] or hi[i] < a) return;
	if(a <= lo[i] and hi[i] <= b){
		lazy[i] += val;
		return;
	}	
	
	prop(i);
	increment(i<<1, a, b, val);
	increment((i<<1)|1, a, b, val);
	update(i);
}

long long minimum(int i, int a, int b){
	if(b < lo[i] or hi[i] < a) return LLONG_MAX;
	if(a <= lo[i] and hi[i] <= b) return Min[i] + lazy[i];

	prop(i);
	
	long long l = minimum(i<<1, a, b);
	long long r = minimum((i<<1)|1, a, b);
	
	update(i);
	return min(l, r);
}

char s[100];
int x, y, z;

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", A+i);

	init(1, 0, n-1);
	scanf("%d%*c", &m);
	while(m--){
		scanf("%[^\n]s", s);
		if(sscanf(s, "%d %d %d", &x, &y, &z) == 2){
			if(x <= y) printf("%lld\n", minimum(1, x, y));
			else printf("%lld\n", min(minimum(1, x, n-1), minimum(1, 0, y)));
		}
		else{
			if(x <= y) increment(1, x, y, z);
			else increment(1, x, n-1, z), increment(1, 0, y, z);	
		}
		getchar();
	}	

	return 0;
}
