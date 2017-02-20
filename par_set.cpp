#include <iostream>
using namespace std;

const int N = 1000;
int a[N];
int memo[N][N];

int dp(int pos, int suma){
	if(pos == n)return (suma%2 == 0); 
    if(memo[pos][suma] != -1)return memo[pos][suma];
    return memo[pos][suma] = dp(pos+1, suma+a[pos]) + dp(pos+1, suma);
}

int main(){

	

	return 0;
}
