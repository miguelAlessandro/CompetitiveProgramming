#include <bits/stdc++.h>
using namespace std;

int s[11][10001];
int n, t;

int main(){

	for(int i = 1; i < 10; ++i){
		for(int j = 0; j <= 9; ++j)
			s[j][i] = s[j][i-1];
		s[i][i] = s[i][i-1]+1;
	}
	for(int i = 10; i <= 99; ++i){
		for(int j = 0; j <= 9; ++j)
			s[j][i] = s[j][i-1];
		s[i%10][i] += 1, 
		s[i/10][i] += 1;	
	}
	for(int i = 100; i <= 999; ++i){
		for(int j = 0; j <= 9; ++j)
			s[j][i] = s[j][i-1];
		s[i%10][i] += 1; 
		s[i/10%10][i] += 1;
		s[i/100][i]	+= 1;
	}
	for(int i = 1000; i <= 9999; ++i){
		for(int j = 0; j <= 9; ++j)
			s[j][i] = s[j][i-1];
		s[i%10][i] += 1, 
		s[i/10%10][i] += 1;
		s[i/100%10][i] +=1;
		s[i/1000][i]+=1;	
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i <= 9; ++i)
			printf("%d%c", s[i][n], i==9?'\n':' ');
	}

	return 0;
}
