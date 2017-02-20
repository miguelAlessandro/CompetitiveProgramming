#include <bits/stdc++.h>
using namespace std;

int t, nc=1;
char c;

int main(){
	
	scanf("%d%*c", &t);
	while(t--){

		bool pie = false;
		bool state;
		int level;
		int pos;
		int line = -1;

		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				int c = getchar();
				if(c == '|' and ((not pie) or (pie and level == i))) line = j;
				if(c == '>' or c == '<'){
					level = i;
					pie = true;
					state = (c == '>');
					pos = j;
				}	
			}

			getchar();

		}

		printf("Case %d: ", nc++);
		if(pos < line)
			puts(state ? "Thik Ball" : "No Ball");
		else
			puts(state ? "No Ball" : "Thik Ball");

		getchar();
	}


	return 0;
}
