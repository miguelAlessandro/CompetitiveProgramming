#include <iostream>
#include <cstdio>
using namespace std;

int mapa[300];
char s[25];
int n, c;

int main(){

	scanf("%s", s);
	scanf("%d%*c", &n);

	while((c = getchar()) != EOF)
		if(c != ' ') mapa[c]++;

	for(int i = 0; s[i] != '\0'; ++i)
		if(mapa[s[i]] == 0){
			puts("NO");
			return 0;
		}
		else mapa[s[i]]--;


	puts("YES");

	return 0;
}
