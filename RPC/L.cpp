#include <bits/stdc++.h>
using namespace std;

int x, n, q;



int c(int k, int n){
	
	for(int i = 1; i <= k; ++i)
		
}

long long expfast(long long a, long long b){
	long long r = 1;
	while(b){
		if(b&1) r = (r*a)%4;
		a = (a*a)%4;
		b >>= 1;
	}
	return r;
}

int main(){

	for(int i = 1; i <= 100000; ++i)
		inv[i] = (i*i)%4; 
	
	dp[1] = 1;
	for(int i = 2; i <= 100000; ++i)
		dp[i] = (inv[i]*dp[i-1])%4;

	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &x, &n);
		int ans = 1LL*(n+1)*(n+2)/2;
		int minus = 2;
		if(x%4 == 0) minus = ans;
		if(x%4 == 1){
			if(n > 2){
				if(n%4 == 1) minus = 3;
				if(n%4 == 2) minus = 2;
				if(n%4 == 3) 
				if(n%4 == 0) 
			} 
			if(n == 2) minus = 2;
			if(n == 1) minus = ans;	
		}
		if(x%4 == 2){
			if(n%4 == 1) minus = 2;
			if(n%4 == 0) minus = ans;
			if(n%4 == 2) minus = ans;
			if(n%4 == 3){
				if((1LL*n*x)%4 == 1) minus = 3;
				else if((1LL*n*x)%4 == 2) minus = 2; 
				else minus = ans;
			} 
		}
		if(x%4 == 3){
			if(n%4 == 3) minus = 3;
			if(n%4 == 1) 
			if(n%4 == 0)  
			if(n%4 == 2) minus = 2;  
		}		
	}

	return 0;
}
