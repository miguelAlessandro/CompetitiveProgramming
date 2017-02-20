#include <bits/stdc++.h>
using namespace std;

int main(){

	string X, Y;
	int s[300], s2[300];
	while(cin >> X >> Y){
		memset(s, 0, sizeof s);
		memset(s2,0, sizeof s2);
		for(auto it : X)
			s[it]++;
		for(auto it : Y)
			s2[it]++;		

		for(int i = 1; i <= 255; ++i)
			for(int j = 0; j < min(s[i], s2[i]); ++j)
				putchar(char(i));
		puts("");
	}

	return 0;
}
