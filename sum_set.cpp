#include <iostream>
using namespace std;

long long memo[N];

long long backtracking(int pos){
	if(pos+1 == n) return a[n-1];
	if(memo[pos] != -1) return memo[pos];
	
	return memo[pos] = 2*backtracking(pos+1) + a[pos]*expfast(2, n-1-pos);
}

int main(){

	


	return 0;
}
