#include <bits/stdc++.h>
using namespace std;

const int N = 2055;
int n, k, x, y;
vector<int> a(N), b, c;

int main(){

	scanf("%d %d %d", &n, &k, &x);

	for(int i = 0; i < n; ++i){
		scanf("%d", &y);
 		a[y]++;
	}
	
	for(int i = 0; i < k; ++i){
		b = a;
		int carry = 0;
		for(int i = 0; i <= 2050; ++i)
			if(b[i]){
				int len = (b[i] - carry + 1)/2;
				a[i^x] += len;
				a[i] -= len;
				carry = (carry + b[i])&1;
			}					
	}

	int mini = 2050;
	int maxi = 0;
	for(int i = 0; i <= 2050; ++i)
		if(a[i]){
			mini = min(mini, i);
			maxi = max(maxi, i);
		}

	printf("%d %d\n", maxi, mini);

	return 0;
}
