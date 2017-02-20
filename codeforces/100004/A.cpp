#include <bits/stdc++.h>
using namespace std;

const int N = 5002;
const int M = 202;
int A[N][N];
int Xi[M], Yi[M];
double X[M], Y[M]; 
int n;

int main(){

	while(scanf("%lf %lf", X+n, Y+n) == 2) n++;	

	for(int i = 0; i < n; ++i)
		Xi[i] = X[i]*100,
		Yi[i] = Y[i]*100;
	
	for(int i = 0; i < n; ++i)
		for(int j = - 250; j <= 250; ++j){
			for(int k = 0; k*k + j*j <= 62500; ++k)
				if(Xi[i] + j >= 0 and Xi[i] + j < N and Yi[i] + k >= 0 and  Yi[i] + k < N)
			 		A[Xi[i] + j][Yi[i] + k]++;
				else continue;

			for(int k = -1; k*k + j*j <= 62500; --k)
				if(Xi[i] + j >= 0 and Xi[i] + j < N and Yi[i] + k >= 0 and  Yi[i] + k < N)
					A[Xi[i] + j][Yi[i] + k]++;
				else continue;
		}

	int ans = 0;
	for(int i = 0; i <= 5000; ++i)
		for(int j = 0; j <= 5000; ++j)
			ans = max(ans, A[i][j]);

	printf("%d\n", ans);


	return 0;
}
