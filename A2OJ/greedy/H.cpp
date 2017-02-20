#include <bits/stdc++.h>
using namespace std;

char s[1005];
int d[30];
int t;

int main(){

	scanf("%d%*c", &t);
	while(t--){
		scanf("%s", s);
		int len = strlen(s);
		memset(d, 0, sizeof d);

		int mini = 25;
		for(int i = 0; i < len; ++i){
			d[s[i] - 'a'] += 1;
			if(s[i]-'a' < mini) mini = s[i]-'a';
		}

		for(int i = mini+1; i < 26; ++i)
			if(d[i]){
				d[mini] += d[i]-1;
				d[i] = 1;
			}

		for(int i = mini; i < 26; ++i)
			for(int j = 0; j < d[i]; ++j)
				putchar(i+'a');
		puts("");
	}

	return 0;
}
