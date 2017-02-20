#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){

	cin >> n >> m;
	switch(n){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			switch(m){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					puts("5");
					break;
				case 6:
				case 7:
					puts("6");
					break;
			}					
	
			break;

		case 2:
			switch(m){
				case 1:
					puts("4");
					break;
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
					puts("5");
					break;
			}						
		
			break;

		case 4:
		case 6:
		case 9:
		case 11:

			switch(m){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					puts("5");
					break;
				case 7:
					puts("6");
					break;
			}					
	

			break;
	}

	return 0;
}
