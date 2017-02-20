#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100002;
int n, r, w, h;
int ft[N], answ[N];

pair<int, int> P[N];
vector< pair<long long, int> > A, B;

void updat(int x, int v){
	while(x < N){
		ft[x] = max(ft[x], v);		
		x += x&(-x);
	}
}

int quer(int x){

	int ans = 0;
	while(x>0){
		ans = max(ft[x], ans);	
		x -= x&(-x);
	}
	return ans;
}


int main(){

	scanf("%d %d %d %d", &n, &r, &w, &h);
	
	for(int a, b, i = 0; i < n; ++i){
		scanf("%d %d", &a, &b);
		A.push_back(make_pair(b + 1LL*a*r, i));
		B.push_back(make_pair(b - 1LL*a*r, i));
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	
	P[A[0].second].second = 1; 
	for(int c = 1, i = 1; i < n; ++i){
		if(A[i].first != A[i-1].first) c++;
		P[A[i].second].second = c;
	}

	P[B[0].second].first = 1;
	for(int c = 1, i = 1; i < n; ++i){
		if(B[i].first != B[i-1].first) c++;
		P[B[i].second].first = c;
	}

	sort(P, P+n);

	for(int i = 0; i < n; ++i){
		answ[i] = 1 + quer(P[i].second);
		updat(P[i].second, answ[i]);	
	}

	int maximum = 0;
	for(int i = 0; i < n; ++i)
		maximum = max(maximum, answ[i]);

	printf("%d\n", maximum);

	return 0;
}
