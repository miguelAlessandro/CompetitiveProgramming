#include <iostream>
#include <cstdio>
using namespace std;

string line;
int pieces[250];

int main(){

	pieces['q'] = 9;
	pieces['r'] = 5;
	pieces['b']	= 3;
	pieces['n'] = 3;
	pieces['p'] = 1;
	pieces['k'] = 0;
	pieces['.'] = 0;
	pieces['Q'] = 9;
	pieces['R'] = 5;
	pieces['B']	= 3;
	pieces['N'] = 3;
	pieces['P'] = 1;
	pieces['K'] = 0;
	pieces['\n'] = 0;

	int w = 0, b = 0, c;
	while((c = getchar()) != EOF)
		if(isupper(c)) w += pieces[c];
		else b += pieces[c];

	if(w < b)
		puts("Black");
	else if(b < w)
		puts("White");
	else
		puts("Draw");

	return 0;
}
