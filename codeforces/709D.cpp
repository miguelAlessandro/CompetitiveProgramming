#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(){

	//scanf("%d", &t);
	//while(t--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		
		if(not b and not c){
			if(not d) for(int i = 0; i <= a; ++i) printf("0");
			else if(not a) for(int i = 0; i <= d; ++i) printf("1");
			else printf("Impossible");
		}
		else if(not c){
			if(b == 1){
				for(int i = 0; i <= a; ++i) printf("0");
				for(int i = 0; i <= d; ++i) printf("1");
			}
			else printf("Impossible");
		}
		else if(not b){
			if(c == 1){
				for(int i = 0; i <= d; ++i) printf("1");
				for(int i = 0; i <= a; ++i) printf("0");
			}
			else printf("Impossible");
		}
		else{
			if(abs(b - c) <= 1){
				if(c > b) printf("1");
				for(int i = 0; i <= a; ++i) printf("0");
				for(int j = 0; j <= d; ++j) printf("1");
				for(int i = 0; i < b+c-1-(b != c); ++i) printf("%c", i%2 == 0 ? '0' : '1');
				if(b > c) printf("1");
			}	
			else printf("Impossible");

		}

		puts("");
	//}

	return 0;
}
