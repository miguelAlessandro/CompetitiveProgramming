#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int dp[300][500];
string s;
int n, t, len;

int backtracking(int pos, int change){

	if((len&1) and pos == len/2){
		if(change == n-1) return 25;
		return change == n;
	}
	else if(len%2 == 0 and pos == len/2) return change == n;	

	if(dp[pos][change] != -1) return dp[pos][change];	

	int ans = 0;
	for(int i = 'a'; i <= 'z'; ++i){
		if(s[len-1-pos] == i and s[pos] == i)
			ans = (ans + backtracking(pos+1, change))%MOD;
		if(s[len-1-pos] != i and s[pos] == i)
			ans = (ans + backtracking(pos+1, change+1))%MOD;
		if(s[len-1-pos] == i and s[pos] != i)
			ans = (ans + backtracking(pos+1, change+1))%MOD;
		if(s[len-1-pos] != i and s[pos] != i)
			ans = (ans + backtracking(pos+1, change+2))%MOD;
	}

	return dp[pos][change] = ans;
}


int main(){

	cin >> t;
	while(t--){
		cin >> n >> s;
	
		memset(dp, -1, sizeof dp);
		len = s.size();

		if(len == 1){
			cout << 25 << endl;	
			continue;
		}

		cout << backtracking(0, 0) << endl;
	}

	return 0;
}
