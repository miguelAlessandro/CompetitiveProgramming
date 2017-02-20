#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int Y[N];
int n, t;


/*int dp(int pos, int t){

	if(pos == n-1) return 1;
	
	int len = n - pos;
	int ans = 0;
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len-1; ++j)
			

}*/


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", Y+i);

		sort(Y, Y+n, greater<int>());



	}

	return 0;
}
