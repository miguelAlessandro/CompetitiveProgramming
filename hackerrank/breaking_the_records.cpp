#include <bits/stdc++.h>
using namespace std;

int n;
int s, mini, maxi;

int main(){

		
	scanf("%d", &n);
	
	scanf("%d", &s);
	mini = s;
	maxi = s;

	int p1 = 0, p2 = 0;
	for(int i = 1; i < n; ++i){
		scanf("%d", &s);	
		if(s < mini) mini = s, p1++;
		if(s > maxi) maxi = s, p2++;
	}

	printf("%d %d\n", p2, p1);

	return 0;
}
