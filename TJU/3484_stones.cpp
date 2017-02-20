#include <cstdio>
#include <iostream>
using namespace std;

int n, t;
int sum, maxi, x;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		maxi = 0; sum = 0;
		while(n--){
			scanf("%d", &x);
			maxi = max(maxi, x);
			sum += x;
		}	

		printf("%d\n", sum-maxi);
	}

	return 0;
}
