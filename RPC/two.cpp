#include <bits/stdc++.h>
using namespace std;

	long long s[1000005];
int main(){


	s[0] = 0;
	for(int i = 1; i <= 1000000; ++i){

		for(int k = 1; k <= 25; ++k)
			s[i] += (i/(1<<k));

		if(2*s[i-1] + 2 == s[i]*(i-1)) printf("%d\n", i);
		s[i] += s[i-1];
	}


	return 0;
}
