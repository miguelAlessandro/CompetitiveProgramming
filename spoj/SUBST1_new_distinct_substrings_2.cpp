#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int K = 300;

int RA[N], TRA[N];
int SA[N], TSA[N];
int Phi[N], PLCP[N];
int C[N], LCP[N];
char A[N];
int n, t;

void countsort(int k){
	memset(C, 0, sizeof C);
	int maxi = max(300, n);
	for(int i = 0; i < n; ++i) C[i+k < n ? RA[i+k] : 0]++;
	for(int i = 0, sum = 0; i < maxi; ++i){
		int t = C[i];
		C[i] = sum;
		sum += t;
	}
	for(int i = 0; i < n; ++i) TSA[C[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for(int i = 0; i < n; ++i) SA[i] = TSA[i];
}

void buildSA(){
	for(int i = 0; i < n; ++i) RA[i] = A[i];
	for(int i = 0; i < n; ++i) SA[i] = i;
	for(int r, k = 1; k < n; k<<=1){
		countsort(k);
		countsort(0);
		TRA[SA[0]] = r = 0;
		for(int i = 1; i < n; ++i)
			TRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] and RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;	
		for(int i = 0; i < n; ++i)
			RA[i] = TRA[i];

		if(RA[SA[n-1]] == n-1)  break;
	}	
}

void computeLCP(){

	Phi[SA[0]] = -1;
	for(int i = 1; i < n; ++i) Phi[SA[i]] = SA[i-1];
	for(int i = 0, l = 0; i < n; ++i){
		if(Phi[i] == -1){
			PLCP[i] = 0;
			continue;
		}
		while(A[i+l] == A[Phi[i]+l]) l++;
		PLCP[i] = l;
		l = max(l-1, 0);
	}
	for(int i = 0; i < n; ++i)
		LCP[i] = PLCP[SA[i]];
}


int main(){

	scanf("%d%*c", &t);
	while(t--){
		n = strlen(gets(A));
		A[n++] = '$';
		buildSA();
		computeLCP();
		long long ans = 0;
		for(int i = 1; i < n; ++i) ans += LCP[i];
		printf("%lld\n", 1LL*n*(n+1)/2 - ans);
	}

	return 0;
}
