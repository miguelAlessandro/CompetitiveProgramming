#include "bits/stdc++.h"
using namespace std;

const int maxN = 1e5 + 5;
int M[maxN], N[maxN];
int expandN[maxN], expandM[maxN];
int dpN[maxN], dpM[maxN];
int n;

int main(){
	
	int nc = 1;
	
	int t;
	scanf ("%d", &t);

	while(t--){
	scanf ("%d", &n);

	for (int i = 0; i < n; ++i){
		int d, a, b;
		scanf ("%d %d %d", &d, &a, &b);	
		M[i] = d+a;
		N[i] = d-b;
	}

	expandN[0] = 0;
	expandM[0] = 0; 
	for (int i = 1; i < n; ++i) {
		
		if (N[i-1] == N[i]) expandN[i] = expandN[i-1];
		else expandN[i] = i;		
	
		if (M[i-1] == M[i]) expandM[i] = expandM[i-1];
		else expandM[i] = i;

	}

	int maxLenght = 0;
	int cnt = 0;
	
	dpN[0] = 1;

	for (int i = 1; i < n; ++i) {	
		
		int pos1 = expandN[i];		
		
		dpN[i] = i - pos1 + 1;
		
		if (pos1 >= 1) { 
			int pos2 = expandM[pos1-1];		
	
			dpN[i] = i - pos2 + 1;
	
			if (pos2 >= 1 and N[pos2 - 1] == N[i]) {
				int pos3 = expandN[pos2 - 1];
				
				dpN[i] = i - pos3 + 1;

				if (pos3 >= 1 and M[pos3 - 1] == M[pos1-1])
					dpN[i] = i - pos2 + 1 + dpN[pos2-1];
			}
		}

	}

	dpM[0] = 1;
	
	for (int i = 0; i < n; ++i) {
		int pos1 = expandM[i];		
		
		dpM[i] = i - pos1 + 1;
		
		if (pos1 >= 1) { 
			int pos2 = expandN[pos1-1];		
	
			dpM[i] = i - pos2 + 1;
	
			if (pos2 >= 1 and M[pos2 - 1] == M[i]) {
				int pos3 = expandM[pos2 - 1];
				
				dpM[i] = i - pos3 + 1;

				if (pos3 >= 1 and N[pos3 - 1] == N[pos1-1])
					dpM[i] = i - pos2 + 1 + dpM[pos2-1];
			}
		}
	}

	

	for (int i = 0; i < n; ++i) {

		if (maxLenght < max (dpN[i], dpM[i])) {	

			maxLenght = max (dpN[i], dpM[i]);
			cnt = 1;
		}
		else if (maxLenght == max(dpN[i], dpM[i])) 
			cnt += 1;
	}

	printf("Case %d: %d %d\n", nc++, maxLenght, cnt);
	}

	return 0;
}

