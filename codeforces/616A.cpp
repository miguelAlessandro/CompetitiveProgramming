#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
char a[N], b[N], c[N], d[N];


int main(){

	scanf("%s%*c%s", a, b);
	
	int la = strlen(a), lb = strlen(b);
	bool ok;
	int laceros = 0;
	ok = false;
	for(; a[laceros] != '\0'; ++laceros)
		if(a[laceros] != '0'){ 
			ok = true;
			break;
		}
		
	if(not ok){
		la = 1;
		laceros = 0; 
		a[0] = '0', a[1] = '\0';  
	}

	int lbceros = 0;
	ok = false;
	for(; b[lbceros] != '\0'; ++lbceros)
		if(b[lbceros] != '0'){
			ok = true;
			break;
		}
	
	if(not ok){
		lb = 1;
		lbceros = 0; 
		b[0] = '0', b[1] = '\0';
	}

	if(la - laceros > lb - lbceros) puts(">");
	else if(la-laceros < lb-lbceros) puts("<");
	else{
		int r = 0;
		for(int i = laceros, j = lbceros; a[i] != '\0' and b[j] != '\0'; ++i, ++j)
			if(a[i] > b[j]){
				r = 1;
				break;
			}
			else if(a[i] < b[j]){
				r = -1;
				break;
			}

		if(r == 0) puts("=");
		if(r == 1) puts(">");
		if(r == -1) puts("<");
	}


	return 0;
}	
